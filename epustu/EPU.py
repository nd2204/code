from selenium import webdriver 
from selenium.webdriver.common.by import By
from captcha import Captcha
import os
import calendar
from datetime import datetime

class EPULoginPage(webdriver.Chrome):
    def __str__(self):
        return f" "

    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self.HOST           = "http://sinhvien.epu.edu.vn/"
        self.DEFAULT_URL    = "Default.aspx"
        self.CALENDAR_URL   = "LichHocLichThiTuan.aspx"

    def init(self):
        self.get(self.HOST + self.DEFAULT_URL)
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
        self.save_screenshot(filename)
        calendar = self.find_element(By.CLASS_NAME, "div-ChiTietLich")
        img = Captcha(calendar.location, calendar.size)
        img = img.extract_image(filename, 1)
        img.save(filename)

    def get_upcoming_calendar(self, count):
        self.get(self.HOST + self.CALENDAR_URL)
        current_month = calendar.month_name[datetime.now().month]
        try:
            os.mkdir(current_month)
        except FileExistsError:
            pass

        for _ in range(count):
            date = self.find_element(By.ID, "ctl00_ContentPlaceHolder_txtDate")
            self.get_calendar_img(current_month + "/" + str(date.get_attribute('value')) + ".png")
            self.find_element(By.ID, "ctl00_ContentPlaceHolder_btnSau").click()
