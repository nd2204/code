# from pkgutil import extend_path
import pytesseract as pt
from pytesseract import image_to_string 
from PIL import Image
from selenium import webdriver 
from selenium.webdriver.common.by import By
import getpass
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

    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self.HOST           = "http://sinhvien.epu.edu.vn/"
        self.PATH           = ( "Default.aspx", "LichHocLichThiTuan.aspx"  )

    def init(self):
        self.get(self.HOST + self.PATH[0])
        self.set_window_size(1120, 2000)

    def login(self, username, password):
        self.save_screenshot("ss.png")
        usr_id         = self.find_element(By.ID, "ctl00_ucRight1_txtMaSV")
        usr_password   = self.find_element(By.ID, "ctl00_ucRight1_txtMatKhau")

        # Handling Captcha
        captcha_input  = self.find_element(By.ID, "ctl00_ucRight1_txtSercurityCode")
        captcha_img    = self.find_element(By.ID, "imgSecurityCode")
        captcha = Captcha(captcha_img.location, captcha_img.size)
        captcha_text = captcha.extract_text(captcha.extract_image("ss.png"))

        # Sending input
        usr_id.send_keys(f'{username}')
        usr_password.send_keys(f'{password}')
        captcha_input.send_keys(f'{captcha_text}')

        # Login
        self.find_element(By.ID, "ctl00_ucRight1_btnLogin").click()
        os.remove("ss.png")

    def get_calendar_img(self, filename):
        self.get(self.HOST + self.PATH[1])
        self.save_screenshot(filename)
        calendar = self.find_element(By.CLASS_NAME, "div-ChiTietLich")
        img = Captcha(calendar.location, calendar.size)
        img = img.extract_image(filename, 1)
        img.save(filename)

if __name__ == "__main__":
    try:
        with open(".cred", "r") as file:
            usr_id = file.readline().strip()
            usr_password = file.readline().strip()
    except FileNotFoundError:
        usr_id = input("Username: ")
        usr_password = getpass.getpass("Password: ")
        remember = input("Remember your password? (y/N): ")
        if remember.startswith("y"):
            with open(".cred", "w") as file:
                file.write(f"{usr_id}\n{usr_password}")

    page = EPULoginPage(options=options, keep_alive=True)
    page.init()
    page.login(usr_id, usr_password)
    page.get_calendar_img("calendar.png")
