from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys
from selenium.common.exceptions import NoSuchElementException 
from env import browser
from time import sleep

def Crawl():
    browser.get("http://vinhdinhcoder.net/Problem/List")
    table = browser.find_element(By.CSS_SELECTOR, ".tm-wrapper .tm-wrapper2 .tm-body .tm-box-body table.data-table-short tbody").find_elements(By.TAG_NAME, "tr")
    table_link = []
    for row in table:
        if (row.find_element(By.CSS_SELECTOR, "td:last-child .passed-failed").get_attribute("class").split(" ")[-1] == "passed"):
            table_link.append("http://vinhdinhcoder.net/Submission/Mine/" + row.find_element(By.CSS_SELECTOR, "td a").get_attribute("href").split("/")[-1])
    table_link.reverse()
    for href in table_link:
        browser.get(href)
        accept = browser.find_element(By.CSS_SELECTOR, "td.accepted")
        id_ac = accept.find_element(By.XPATH, "..").find_element(By.CSS_SELECTOR, "a.submission-status").get_attribute("id")
        id_problem = accept.find_element(By.XPATH, "..").find_element(By.CSS_SELECTOR, "td.left a").get_attribute("innerHTML").split("-")[0].strip()
        loai = accept.find_element(By.XPATH, "..").find_element(By.CSS_SELECTOR, "td.left + td").get_attribute("innerHTML").strip()
        browser.get(f"http://vinhdinhcoder.net/Submission/Detail/{id_ac}/?fullScreen=1")
        code = browser.find_element(By.CSS_SELECTOR, "textarea#SubmitCode").get_attribute("value")
        id_num = href.split("/")[-1]
        if ("C++" in loai):
            with open(f"{id_num}_{id_problem}.cpp", "w", encoding="utf-8") as f:
                f.write(f"// {id_problem}\n\n")
                f.write(f"{code}")
        elif ("Python" in loai):
            with open(f"{id_num}_{id_problem}.py", "w", encoding="utf-8") as f:
                f.write(f"# {id_problem}\n\n")
                f.write(f"{code}")