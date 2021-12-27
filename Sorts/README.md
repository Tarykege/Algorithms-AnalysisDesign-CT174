# Sorts

## day 1 (27/12/2021): INSERT SORT
<img src="https://www.doabledanny.com/static/92b034385c440e08bc8551c97df0a2e3/2.gif"/>
### Ý tưởng
```
Bắt chước cách sắp xếp quân bài của những người chơi bài
```

### Nguyên lý
```
- Chạy từ đầu đến cuối mảng
- Tại vòng lặp i, coi nhu dãy từ [0,i-1] đã được sắp xếp
- Chèn phần từ a[i] vào vị trí thích hợp (sao cho phần tử đúng trạng thái sắp xếp khi thêm vào)
- Sau vòng lặp thứ i thì dãy [0,i] đã được sắp xếp.  
```
### Độ phức tạp
```
Độ phức tạp về thời gian:
	Trường hợp tốt: O(n)
	Trung bình: O(n^2)
	Trường hợp xấu: O(n^2)
	Không gian phụ trợ: O(1)
```

## day 1.2 (27/12/2021): SELECTION SORT

### Ý tưởng
```
Đi tìm phần tử có giá trị nhỏ nhất và sắp chúng tuần tự từ trái qua phải
```

### Nguyên lý
```
- Chạy từ đầu đến cuối mảng
- Tại vòng lặp thứ i, tìm phần tử nhỏ nhất từ [i+1,n-1], nếu phần tử nhỏ nhất đó nhỏ hơn a[i] thì swap
- Sau vòng lặp thứ i, thì dãy [0,i] đã được sắp xếp
```
### Độ phức tạp
```
Độ phức tạp về thời gian:
	Trường hợp tốt: O(n^2)
	Trung bình: O(n^2)
	Trường hợp xấu: O(n^2)
Không gian phụ trợ: O(1)
```
