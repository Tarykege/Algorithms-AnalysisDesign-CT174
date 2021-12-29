# Sorts

## day 1 (27/12/2021): INSERT SORT
<img src="https://upload.wikimedia.org/wikipedia/commons/9/9c/Insertion-sort-example.gif" width="500px" height="300px"/>

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
- Độ phức tạp về thời gian:
	Trường hợp tốt: O(n)
	Trung bình: O(n^2)
	Trường hợp xấu: O(n^2)
- Không gian phụ trợ: O(1)
```

## day 1.2 (27/12/2021): SELECTION SORT
<img src="https://nguyenvanhieu.vn/wp-content/uploads/2018/07/thuat-toan-selection-sort.gif" width="500px" height="300px"/>

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
- Độ phức tạp về thời gian:
	Trường hợp tốt: O(n^2)
	Trung bình: O(n^2)
	Trường hợp xấu: O(n^2)
- Không gian phụ trợ: O(1)
```

## day 2 (28/12/2021): BUBBLE SORT
<img src="https://www.programmingsimplified.com/images/c/bubble-sort.gif" width="600px" height="300px"/>

### Ý tưởng
```
Giá trị lớn nhất sẽ bị đẩy lên cuối mảng
```

### Nguyên lý
```
- Chạy từ đầu đến cuối mảng
- Nếu phần tử đứng trước lớn hơn phần tử đứng sau thì đổi chỗ
- Sau mỗi vòng lặp thì phần tử lớn nhất sẽ trôi xuống dưới và vòng lặp thứ n-i-1 sẽ không xét nữa
```
### Độ phức tạp
```
- Độ phức tạp về thời gian:
	Trường hợp tốt: O(n)
	Trung bình: O(n^2)
	Trường hợp xấu: O(n^2)
- Không gian phụ trợ: O(1)
```
## day 3 (29/12/2021): QUICK SORT
<img src="https://upload.wikimedia.org/wikipedia/commons/9/9c/Quicksort-example.gif" width="500px" height="300px"/>

### Ý tưởng
```
Thuật toán sắp xếp quick sort là một thuật toán chia để trị( Divide and Conquer algorithm).
```

### Nguyên lý
```
B1: chọn pivot
	Nó chọn một phần tử trong mảng làm điểm đánh dấu(pivot). Thuật toán sẽ thực hiện chia mảng thành các mảng con dựa vào pivot đã chọn. Việc lựa chọn pivot ảnh hưởng rất 		nhiều tới tốc độ sắp xếp. Nhưng máy tính lại không thể biết khi nào thì nên chọn theo cách nào. Dưới đây là một số cách để chọn pivot thường được sử dụng:
	Luôn chọn phần tử đầu tiên của mảng
	Luôn chọn phần tử cuối cùng của mảng
	Chọn một phần tử random
	Chọn một phần tử có giá trị nằm giữa mảng(median element)
B2: phân bố lại mảng theo pivot
B3: Chia ra
```
### Độ phức tạp
```
- Độ phức tạp về thời gian:
	Trường hợp tốt: O(nlog(n))
	Trung bình: O(nlog(n))
	Trường hợp xấu: O(n^2)
- Không gian phụ trợ: O(log(n))
```
