# hw02
1. 讀取button值來決定要上數、下數還是select
2. 每次改變的frquency值是10
3. 每次改變frequemcy都直接顯示在uLCD上
4. 當按下sel時，傳當時的frequency來計算應該呈現的週期
5. 用該週期產生一三角波
6. 方式為鋸齒波上升在下降，只是讓鋸齒很小
7. 將該訊號analog out經過濾波器
8. 印出一個周期內的經濾波的所有數據點
9. python檔讀出值並繪圖
10. 結果體現low pass filter，較高頻率會被濾掉 
