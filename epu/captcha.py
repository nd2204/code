import pytesseract as pt
from pytesseract import image_to_string 
from PIL import Image

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
            self.y + self.height
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
