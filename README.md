# CTF Manager 

Chương trình quản lý cuộc thi CTF và quản lý các đội thi/thành viên của đội thi trong cuộc thi.  
*Bài tập OOP*

## Thành viên

1. Đoàn Nguyễn Đăng Khoa - 20521463
2. Trần Lê Đại Nghĩa - 20520252
3. Trần Quốc Đạt - 20521179

## Usage

Khi mở ứng dụng, việc đầu tiên là nhập thông tin của kỳ thi.  
__Lưu ý:__ phần format __chỉ__ có 2 format là (nhập đúng y vậy)

| Format        |
| ------------- |
| Jeopardy      | 
| Attack-Defense|

__Lưu ý:__ Only for Windows.  
>Nếu muốn dùng cho GNU/Linux hoặc MacOS
vui lòng liên hệ

## Các chức năng

Chương trình gồm 2 menu chính:

#### Main menu

1. Xem thông tin cuộc thi
>Xuất thông tin về cuộc thi

2. Xem thông tin các đội thi
>Xuất các đội thi trong cuộc thi

3. Xem top 3 đội thi
>Xem top 3 đội thi

4. Đăng ký tham gia
    >- Bao gồm: tên đội, tên đội trưởng, mật khẩu, các thành viên trong nhóm

5. Kiểm tra xem nhóm X đã tham gia chưa

6. Đội trưởng quản lý nhóm
>##### leaderPanel
    >>- Yêu cầu: tên nhóm và mật khẩu của đội trưởng.
    >>- Có thể thay đổi:
        - Tên nhóm
        - Xem thành viên trong đội
        - Xóa thành viên
        - Thêm thành viên
        - Đổi mật khẩu
        
#### Admin Panel

>_Để truy cập Admin Panel, tại Main menu nhập __"42069"___

1. Chỉnh sửa thông tin của cuộc thi
>Truy cập tới __EventEditorPanel__  
> ##### EventEditorPanel
>> 1. Đổi tên cuộc thi
> 2. Đổi tên nhà tổ chức/tài trợ
> 3. Đổi ngày tổ chức cuộc thi
> 4. Thay đổi giá trị giải thưởng
> 5. Thay đổi format cuộc thi __theo Format table ở trên__

2. Chỉnh sửa điểm cho đội X

3. Xóa đội thi X khỏi cuộc chơi

4. Xem thông tin của cuộc thi

5. Xuất danh sách đội thi

6. Quản lý các đội thi
> Truy cập tới TeamEditorPanel
> ##### TeamEditorPanel
>> Sẽ đưa ra các lựa chọn các đội đang tham gia cuộc thi, nhập số tương ứng để thay đổi như trong __leaderPanel__

## Bug report

Please contact khoadnd03@gmail.com
