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
<img src="data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAASIAAACuCAMAAAClZfCTAAAAclBMVEX///8AAAC8vLydnZ1oaGje3t75+fmYmJikpKTPz8+ysrL39/f09PTo6Ojg4OBvb2/Hx8eqqqpiYmLu7u5DQ0MYGBg7Ozs1NTW/v792dnYoKCiPj48ICAhISEjV1dVVVVWAgIAuLi4dHR1RUVF9fX2KiorG5jpVAAADl0lEQVR4nO3XyxaiOBCAYQvlpiAXQQFBFPX9X3GC9nQv2iq7mdWc838bF4khFJVKsloBAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAADgf8qP9npjuo2iIt/9h+EvboTIS+xOXhQvG71Zr9fbg96+fvPUDnnkBjACMEsz0QfwW3GOhfKGifdjCutQe8W8nEforsZrrFbxJGd7lor10Q0+PVO1g7yVwefmoKhca59drIfsM9FDlF6l3XrnrlMCkG7kX9HnHpe7jIUX9nI15hAM0ofWJDVrkaIpRI/vRarcc7QPeKmlbYpRMj2PDtv5JdUQ5bcqd7nykPPnNNrF8/O9fJRBecZZynjONhEjjZ7SLQrRoZPGpYcnR20dn+VpDbDLpHXzaqpODUGwrets1EPU1KXvfsLXQLrLIOpnavzX72SsZk/aQZaEaCvD6zePlXW0KmVrjhDH8xrdl5PaLQnLPDZq0WWcvNdy2mpzmAXZ90pSi7rc97dTsixEmba8fz22Dx9ZG/pmp+TZb/SFlqar/UYPUdAMQ5aNp9BMomI66vXyLRZR2zYuBatFIRpkv91sNnq1DtxGMZfj0tgv9+V4s8v1yjdCNFfb+RFra9c/lMYAP4x6np3npmUhOsqje+1XWpY0Is90H5dWobi4AW6heSixQnQp+7O/L46TtdCiqfqWRFe5awN49ZgsD5F0frq/S6Z0SNJ0fnd/7PSSFKSp19VmyTJCFEQSzq8WdcZKSr5UqtUcoUn7in41zS9Rydoe4qOjnOY/p/XRXiiH65diudUTcWaEKG3fG0Jail7OmmNvH06TTO5qnq9rqZxeujE3R/lkeG/pQTkVZr9d9CVEl2qwTvdGiPZZ/wpRYoXoLJlZzJtBSn2lP3+ePb8XtN+0cp1/dmVt72yH55d1HB8r6wMZIUrCdxbllZEoV3udFTd5GrUweFlYiyLpX2P0NyUHWmnnn8N4+1xrErm93j0XY9e3y3VT36KdOx0ZieKPYi3juPqj7FgWIncgHVfz+XBU2nN3QXFZtpHH53bXcndVNq/tA5a56UfvNXDSY+ydKusDtD/XkXkTWBgi/z20ev9YPd4dRm23SaZ3B/vpvnmsyeertHX9iOrS2PIP45+F6LTwpn9wV8z+YUyvcPOflBvmLGjdyer492Xwb6x7+/4GAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAADw1T/PKSkj/8dOuAAAAABJRU5ErkJggg==" width="500px" height="300px"/>

### Ý tưởng
```
Là một thuật toán hiệu quả dựa trên việc phân chia mảng dữ liệu thành các nhóm phần tử nhỏ hơn
```

### Nguyên lý
>Thuật toán sắp xếp quick sort là một thuật toán chia để trị( Divide and Conquer algorithm). Nó chọn một phần tử trong mảng làm điểm đánh dấu(pivot). Thuật toán sẽ thực hiện chia mảng thành các mảng con dựa vào pivot đã chọn. Việc lựa chọn pivot ảnh hưởng rất nhiều tới tốc độ sắp xếp. Nhưng máy tính lại không thể biết khi nào thì nên chọn theo cách nào. Dưới đây là một số cách để chọn pivot thường được sử dụng:
>Luôn chọn phần tử đầu tiên của mảng
>Luôn chọn phần tử cuối cùng của mảng
>Chọn một phần tử random
>Chọn một phần tử có giá trị nằm giữa mảng(median element)
### Độ phức tạp
```
- Độ phức tạp về thời gian:
	Trường hợp tốt: O(nlog(n))
	Trung bình: O(nlog(n))
	Trường hợp xấu: O(n^2)
- Không gian phụ trợ: O(log(n))
```
