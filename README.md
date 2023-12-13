Gettoken():讀檔，並將每一行程式碼做切割，得到token，如果是第一次就呼叫pass1()，
	第二次就呼叫passs2()，在做pass2之前會使用CheckSyntax()去檢查Syntax，
	是false就輸出錯誤訊息跳過這行，以及使用Pass2CheckFormat()去將會使用到
	NIXBPE的地方設為true(他們是布林值)，做完這兩個動作就去執行pass2。

Pass1():看整行程式碼的第一個，是Symbol或是literal就跟著地址一起放入Table中，
	如果不是第一個的變數，就放進Table但地址先設為-1，pseudo code拉出來依據不同的
	pseudo code做不同的處裡，在處理時順邊翻Opcode。
	還有算地址，SIC是每個指令過後就將地址+3，遇到pseudo code不加3，
	pseudo code有自己加位址的方式。
	SICXE:依照format的格式加，pseudo code一樣有他自己的格式去加地址。

Pass2():SIC跟SICXE有不同的pass2()

SIC:檢查第一個token是不是excutable instruction是就去instruction Table
    把Opcode取出(因為如果是sumbol或是literal出現在第一個那是pass1的事情)，
    是pseudo code就不用處裡(pass1處理)，後面遇到symbol or literal
    就去他們的Table把地址取出，如果有X要另外算Opcode，
    沒有的話直接合併instruction opcode  and symbol address。

SICXE:依照FORMAT的格式去執行，看到instruction就去取opcode，看到symbol就取symbol address，
      會將之前所得到的NIXBPE與opcode以及address使用Pass2Combine()結合成最終的opcode。

Pass2Combine(string  op1, string address):將op1,address與NIXBPE組合並翻成16進位Opcode。

PassCheckFormat():如果有+號就是format4，沒有的話就看intruction的規定去設定format。
   
Pass2CheckFormat():根據有使用到的東西設定NIXBPE，例如:#就是I…。

Find系列:去symbol, literal, instruction, register Table裡面找東西，找到回傳true。

Get系列(string, string)|(string, int):有分為一般的跟Int的，
                        前者會將第二個在Table中的address以string的方式改變，後者則為int。
