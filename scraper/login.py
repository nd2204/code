# from pkgutil import extend_path
import pytesseract as pt
from pytesseract import image_to_string 
from PIL import Image
from selenium import webdriver 
from selenium.webdriver.common.by import By
import getpass
import time
import os

options = webdriver.ChromeOptions()
options.binary_location = "/usr/bin/"

CalendarSite    = "http://sinhvien.epu.edu.vn/LichHocLichThiTuan.aspx"

class Captcha:
    def __init__(self, location, size):
        self.width  = size['width']
        self.height = size['height']
        self.x      = location['x']
        self.y      = location['y']

    def __str__(self):
        return f"width: {self.width}\n" + \
               f"height: {self.height}\n" +\
               f"x: {self.x}\n" + \
               f"y: {self.y}"

    def extract_image(self, filename, scale=2):
        img = Image.open(filename)
        img = img.crop((
            self.x,
            self.y,
            self.x + self.width,
            self.y + self.height,
        ))
        width, height = img.size[0], img.size[1]
        img = img.resize((width*scale, height*scale))
        img.save("captcha.png")
        return img

    def extract_text(self, img_object):
        pt.pytesseract.tesseract_cmd = "/usr/bin/tesseract"
        try:
            captcha_text = pt.image_to_string(img_object)
            return captcha_text.strip()
        except Exception as e:
            print(f"Error: {e}")
            return None

class EPULoginPage(webdriver.Chrome):
    def __str__(self):
        return f"{self.captcha_}"

    def init(self):
        self.URL           = "http://sinhvien.epu.edu.vn/Default.aspx"
        self.get(self.URL)
        self.set_window_size(1120, 900)
        self.usr_id        = self.find_element(By.ID, "ctl00_ucRight1_txtMaSV")
        self.usr_password  = self.find_element(By.ID, "ctl00_ucRight1_txtMatKhau")
        self.captcha_input = self.find_element(By.ID, "ctl00_ucRight1_txtSercurityCode")
        self.captcha_img   = self.find_element(By.ID, "imgSecurityCode")

    def login(self, username, password, captcha):
        self.usr_id.send_keys(f'{username}')
        self.usr_password.send_keys(f'{password}')
        # self.captcha_text = extract_captcha(captcha.location, captcha.size)
        self.captcha_input.send_keys(f'{captcha}')
        self.find_element(By.ID, "ctl00_ucRight1_btnLogin").click()

if __name__ == "__main__":
    usr_id = input("Username: ")
    usr_password = getpass.getpass("Password: ")

    # login_to_website(LoginSite, usr_id, usr_password)
    # os.remove("screenshot.png")
    page = EPULoginPage(options=options, keep_alive=True)
    page.init()
    page.save_screenshot("ss.png")

    captcha = Captcha(page.captcha_img.location, page.captcha_img.size)
    captcha_text = captcha.extract_text(captcha.extract_image("ss.png"))

    page.login(usr_id, usr_password, captcha_text)


