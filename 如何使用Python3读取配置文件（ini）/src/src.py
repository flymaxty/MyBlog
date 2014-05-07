# -*- coding: utf-8 -*-

import configparser

#读取配置文件
config=configparser.ConfigParser()
config.read("IpConfig.ini")

#写入宿舍配置文件
try:
    config.add_section("School")
    config.set("School","IP","10.15.40.123")
    config.set("School","Mask","255.255.255.0")
    config.set("School","Gateway","10.15.40.1")
    config.set("School","DNS","211.82.96.1")
except configparser.DuplicateSectionError:
    print("Section 'School' already exists")

#写入比赛配置文件
try:
    config.add_section("Match")
    config.set("Match","IP","172.17.29.120")
    config.set("Match","Mask","255.255.255.0")
    config.set("Match","Gateway","172.17.29.1")
    config.set("Match","DNS","0.0.0.0")
except configparser.DuplicateSectionError:
    print("Section 'Match' already exists")

#写入配置文件
config.write(open("IpConfig.ini", "w"))

ip=config.get("School","IP")
mask=config.get("School","mask")
gateway=config.get("School","Gateway")
dns=config.get("School","DNS")

print((ip,mask+"\n"+gateway,dns))