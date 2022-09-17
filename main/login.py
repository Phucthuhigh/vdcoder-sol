from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys
from env import browser

def Login():
    name = "Monarch"
    password = "0612@aqws"

    browser.get("http://vinhdinhcoder.net/Account/LogIn")

    browser.find_element(By.ID, "Email").send_keys(name)
    browser.find_element(By.ID, "MatKhau").send_keys(password)

    browser.find_element(By.CSS_SELECTOR, 'input[src="/Images/login-button.png"]').click()