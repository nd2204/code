# from pkgutil import extend_path
import getpass
import os
import sys

from EPU import EPULoginPage, webdriver

options = webdriver.ChromeOptions()
options.binary_location = "/usr/bin/"
# options.add_argument('headless')

browser = webdriver.getd

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Missing argument")
        exit(1)
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
    page.get_upcoming_calendar(int(sys.argv[1]))
