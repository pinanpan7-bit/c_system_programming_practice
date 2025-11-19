#  C 系統程式練習紀錄（C System Programming Practice）

這個 Repo 是我在練習 C 語言底層能力時所建立的練習紀錄。  
內容包含基礎語法、指標、動態記憶體、以及用 C 實作資料結構。  
我主要的目標是強化：  
- 系統底層 C 語言能力  
- 正確的指標操作  
- malloc/free 記憶體管理概念  
- linked list 等資料結構邏輯  

這些能力是未來在 Firmware / Embedded / Networking / 系統軟體領域中所需要的核心。

---

##  資料夾說明

### **`basis/` — 基礎語法練習**
這個資料夾放的是一些 C 語言基礎練習，  
包含：

- if / for / while  
- 基本輸入輸出  
- 函式拆解  
- 初階指標操作  
- 其他簡單題目  

主要是用來熟悉語法與打好基礎的練習。

---

### **`data_structure/` — 資料結構練習（C 實作）**
這是我花較多時間練習的部分，內容包含：

- linked list（多種操作）
- stack / queue（視後續新增）  
- 節點新增、刪除、反轉  
- 快慢指標（fast/slow pointer）  
- 動態記憶體管理（malloc/free）  
- NULL 處理與邏輯邊界判斷  

這些題目主要用來訓練「系統程式常用的 C 語言能力」。

---

##  代表作品（Linked List / System C Practice）

以下是此 Repo 中較具代表性的題目：

### **1️⃣ linked_list_advanced.c**

內容包含：

- 新增 / 刪除節點  
- 反轉 linked list  
- 找中間節點（快慢指標）  
- 移除特定值  
- 合併兩個排序 list  
- 遞迴反向列印  
- linked list 相交判斷  
- 遞迴求長度  
- 釋放整條 linked list 記憶體  

>  這題整合多種 linked list 核心技巧，是我練習 C 資料結構時的主要作品。

---

### **2️⃣ advanced_design.c**

內容包含：

- 判斷 linked list 是否有環（Floyd Cycle Detection）  
- 找環的起點  
- 判斷兩條 linked list 是否相交  

>  練習更進階的 linked list 走訪邏輯與快慢指標技巧。

---

##  練習目標

- 建立系統性的 C 語言思考  
- 熟悉 pointer、linked list、動態記憶體  
- 學會處理常見邊界條件與記憶體釋放  
- 為往後 Firmware / Embedded / Networking 等工作打底  

---

##  後續預計加入的內容
- file I/O 練習  
- 自訂字串函式  
- 更多 linked list 題目  
- memory pool / allocator 相關練習  
- 小型 CLI 工具  

---

##  編譯方式

```bash
gcc filename.c -o program
./program
