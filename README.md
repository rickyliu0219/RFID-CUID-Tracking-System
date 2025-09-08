# RFID CUID Tracking System (C Language Version)  

## Overview / 專案概述
This is a simple RFID CUID tracking system implemented in C.  
It uses a CSV file (`products.csv`) to store product information and simulates tracking products using RFID CUIDs.  

這是一個簡單的 RFID CUID 追蹤系統，使用 C 語言實作。  
系統使用 CSV 檔案（`products.csv`）存放產品資訊，模擬使用 RFID CUID 追蹤產品。

Tested on Windows with Dev-C++.

在 Windows 系統下使用 Dev-C++ 測試通過。

---

## Features / 功能
1. **Add Product / 新增產品**  
   - Input product name and CUID / 輸入產品名稱和 CUID  
   - Default status is `InProgress` / 預設狀態為 `InProgress`  
   - Saves to `products.csv` / 資料會存入 `products.csv`  

2. **Update Status by CUID / 根據 CUID 更新狀態**  
   - Input CUID to find the product / 輸入 CUID 找到產品  
   - Update the status (e.g., `Done`, `InProgress`, `Shipped`) / 更新產品狀態，例如 `Done`、`InProgress`、`Shipped`  

3. **List All Products / 列出所有產品**  
   - Display all products in the CSV / 顯示 CSV 中所有產品  

4. **Search Product by CUID / 根據 CUID 搜尋產品**  
   - Quickly find a product using its CUID / 使用 CUID 快速搜尋產品  

5. **Exit / 離開程式**  
   - Quit the program / 退出程式

---

## Requirements / 系統需求
- Windows OS / Windows 系統  
- Dev-C++ (or any C compiler for Windows) / Dev-C++ 或其他 Windows C 編譯器  
- `products.csv` file in the same folder as `main.c` / `products.csv` 檔案需與 `main.c` 放在同一資料夾  

---

## Setup & Run / 安裝與執行

1. **Prepare CSV File / 準備 CSV 檔案**  
   Create a CSV file named `products.csv` in the project folder with the following format:

   在專案資料夾建立 CSV 檔案 `products.csv`，格式如下：

   ```csv
   Name,CUID,Status
   SampleProduct1,CUID00001,InProgress
   SampleProduct2,CUID00002,InProgress
