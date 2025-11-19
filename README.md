#  C 系統程式練習紀錄（C System Programming Practice）

這個 Repo 是我在加強 C 語言底層能力時整理的練習紀錄。  
因為未來希望往 Firmware / Embedded / Networking / 系統軟體相關職位發展，  
所以用比較扎實的方式把 C 基礎補強起來，特別是指標、記憶體、資料結構等部分。

內容會持續更新，當作自己學習系統程式的記錄。

---

##  資料夾分類

### **`basis/` — 基礎語法練習**
這部分主要用來確認語法與熟悉寫 C 的手感，內容包含：

- if / for / while  
- 基本輸入輸出  
- 函式拆解  
- 初階指標使用  

---

### **`data_structure/` — 資料結構（C 語言實作）**
這是我花比較多時間練習的部分，包含：

- linked list（多種版本）  
- stack / queue  
- 各種節點操作（新增、刪除、反轉、合併）  
- 使用快慢指標、遞迴、動態記憶體等技巧  

透過這些練習，熟悉 malloc/free、NULL 處理、記憶體釋放、邊界條件等觀念。

---

##  代表作品（C 資料結構練習）

下面列出幾個比較有代表性的題目，主要用來加強指標處理與底層邏輯。

### **1️⃣ Linked List 進階操作（linked_list_advanced.c）**  
包含：

- 新增 / 刪除節點  
- 反轉 linked list  
- 找中間節點（快慢指標）  
- 移除所有特定值  
- 合併兩個排序過的 linked list  
- 遞迴反向列印  
- linked list 相交判斷  
- 遞迴求長度  
- 完整釋放記憶體（free）  

這份練習主要用來強化指標、動態記憶體管理、NULL 判斷等底層能力。

---

### **2️⃣ Cycle Detection（advanced_design.c）**  
練習 Floyd Cycle-Finding Algorithm（快慢指標），內容包括：

- 判斷 linked list 是否有環  
- 找出環的起始位置  
- 找兩條 linked list 的相交點  

這題目讓我練到指標走訪、邏輯推導與 linked list 的更進階用法。

---


##  練習目標

- 更熟悉指標與記憶體的概念  
- 手刻資料結構，加深底層理解  
- 除錯 segmentation fault  
- 建立比較系統性的 C 語言思考  
- 為 Firmware / BIOS / Embedded / Networking 打底  

---

##  後續預計補充內容

- file I/O  
- 自訂 string function  
- memory pool / 簡易 allocator  
- 更多 linked list 題目  
- 小型工具（CLI 小程式）

---

##  編譯方式

```bash
gcc filename.c -o program
./program
