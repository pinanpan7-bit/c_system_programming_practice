#  C 系統程式練習紀錄（C System Programming Practice）

這個 Repo 是我整理自己在練 C 系統程式時的學習紀錄。  
因為未來想往 **Firmware / Embedded / Networking / 系統軟體** 相關職位發展，  
所以把重點放在：**指標、動態記憶體、資料結構（特別是 linked list）**。

---

##  目標與練習方向

- 熟悉指標（pointer）與記憶體概念  
- 手刻資料結構（linked list / stack / queue）  
- 強化 malloc/free、NULL 處理、邏輯推導  
- 練習會在 Firmware / Embedded / Networking 等領域用到的 C 基礎  
- 養成乾淨、可維護的程式習慣  

---

##  代表作品（Linked List / Pointer / Memory）

### **1️⃣ linked_list_advanced.c**

內容包含：

- 新增 / 刪除節點  
- 反轉 linked list  
- 移除特定值  
- 找中間節點（快慢指標）  
- 合併兩個排序 linked list  
- 遞迴反向列印  
- linked list 相交  
- 遞迴求長度  
- 完整釋放記憶體  

**這題整合多種 linked list 基礎與中階技巧。**

---

### **2️⃣ linked_list_cycle_intersection.c**  

內容包含：

- Floyd Cycle Detection（快慢指標）  
- 找環的起點  
- 判斷兩條 linked list 是否相交  

**練習更進階的 linked list 走訪與指標推導技巧。**

---

### **3️⃣ transformation.c（進階 linked list 題組）**

包含多個進階 linked list 題目：
- 區段反轉（reverseBetween）
- K-group 反轉（reverseKGroup）
- 判斷回文（isPalindrome）
- Odd-Even 重組
- 基礎反轉與輔助函式（append / freeList / printList）

**這份檔案主要用來練習更複雜的指標走訪、節點重新串接與記憶體管理。**

---

##  其他資料夾說明

### **`0_basis_practice/` — 早期語法練習（非重點）**

放一些基本語法題（if / for / while、matrix、factorial 等）。  
主要為早期練習 C 語法使用，真正的重點在 `data_structure/`。

---

##  未來會補充的內容

- file I/O  
- 自訂字串函式  
- 更多 linked list 題目  
- memory pool / allocator  
- 小工具（CLI 程式）

---

##  編譯方式

```
gcc filename.c -o program
./program
```

---

##  備註

如果有寫得不好的地方也歡迎提出建議。  
這個 Repo 主要作為我的 C 系統程式練習紀錄，也會持續更新。
