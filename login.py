from pkgutil import extend_path
import pytesseract as pt
from pytesseract import image_to_string 
from PIL import Image 
from selenium import webdriver 
import time
from selenium.webdriver.common.by import By
import os

options = webdriver.ChromeOptions()
options.binary_location = "/usr/bin/"

def img_resize(filename, sizeX, sizeY):
    img = Image.open(filename)
    img = img.resize((img.size[0]*sizeX, img.size[1]*sizeY))
    img.save(filename)

def img_crop(filename, left, top, right, bottom):
    img = Image.open(filename)
    img = img.crop((left,top,right,bottom))
    img.save(filename)

def get_captcha_text(location, size):
    pt.pytesseract.tesseract_cmd = "/usr/bin/tesseract"
    img_crop("screenshot.png", location['x'], location['y'],
             location['x']+size['width'], location['y']+size['height'])
    img_resize("screenshot.png", 2, 2)

    try:
        captcha_text = image_to_string(Image.open('screenshot.png'))
        return captcha_text.strip()
    except Exception as e:
        print(f"Error: {e}")
        return None

def login_to_website(url, username, password):
    driver = webdriver.Chrome(options=options, keep_alive=True)
    driver.get(url)
    driver.set_window_size(1120, 900)
    driver.save_screenshot('screenshot.png')

    usr_id = driver.find_element(By.ID, "ctl00_ucRight1_txtMaSV")
    usr_password = driver.find_element(By.ID, "ctl00_ucRight1_txtMatKhau")
    captcha_input = driver.find_element(By.ID, "ctl00_ucRight1_txtSercurityCode")
    captcha = driver.find_element(By.ID, "imgSecurityCode")

    try:
        usr_id.send_keys(f'{username}')
        usr_password.send_keys(f'{password}')
        captcha_text = get_captcha_text(captcha.location, captcha.size)
        captcha_input.send_keys(captcha_text)
        driver.find_element(By.ID, "ctl00_ucRight1_btnLogin").click()
        calendarSite = "http://sinhvien.epu.edu.vn/LichHocLichThiTuan.aspx"
        driver.get(calendarSite)
        driver.save_screenshot('calendar.png')
        print("Saved to calendar.png")
        time.sleep(5)
    except Exception as e:
        print(f"{e} Retrying")

if __name__ == "__main__":
    loginSite = "http://sinhvien.epu.edu.vn/Default.aspx"
    calendarSite = "http://sinhvien.epu.edu.vn/LichHocLichThiTuan.aspx"
    usr_id = input("Username: ")
    usr_password = input("Password: ")
    login_to_website(loginSite, usr_id, usr_password)
    os.remove("screenshot.png")
    
