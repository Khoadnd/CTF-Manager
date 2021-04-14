# CTF Manager

Chương trình quản lý __các__ cuộc thi __CTF__ và __Các__ đội thi/thành viên của đội thi trong __từng__ cuộc thi  
_Bài tập OOP ngày 15/4/2021, chỉ sử dụng được cho windows do có `system("clear");` và `system("pause")`_
## Thành viên
1. Đoàn Nguyễn Đăng Khoa - 20521463
2. Trần Lê Đại Nghĩa - 20520252
3. Trần Quốc Đạt - 20521179

## Usage

Khi mở ứng dụng, ứng dụng sẽ yêu cầu nhập một kỳ thi để khởi tạo.  
__Lưu ý:__ phần format chỉ có 2 format là:  

| Format         |
| ---------------|
| Jeopardy       |
| Attack-Defense |

### Các menu

Chương trình gồm có 2 menu:

#### _menu

| Choice | Menu                                                  |
| ------ | ----------------------------------------------------- |
| 1      | Đăng ký thêm cuộc thi mới _(password: init)_          |
| 2      | Hủy cuộc thi _(admin privilege required)_             |
| 3      | Xem các cuộc thi đang diễn ra                         |
| 4      | Xem top 3 cac cuoc thi co so luong tham gia dong nhat |
| 5      | Xem cuoc thi, tham gia cuoc thi, chinh sua cuoc thi   |
| 0      | Thoát khỏi chương trình                               |

#### Main Menu

| Choice | Menu                                                  |
| ------ | ----------------------------------------------------- |
| --     | Tên cuộc thi: Tên cuộc thi bạn đang xem               |
| --     | Status: Cuộc thi đang diễn ra / Cuộc thi chưa diễn ra |
| 1      | Xem thông tin cuộc thi                                |
| 2      | Xem thông tin các đội thi                             |
| 3      | Xem top 3 đội thi có điểm cao nhất                    |
| 4      | Đăng ký tham gia cuộc thi                             |
| 5      | Kiểm tra nhóm X đã tham gia chưa                      |
| 6      | Team leader quản lý nhóm, truy cập tới leaderPanel    |
| 0      | Quay về _menu                                         |

## For admin

Mật khẩu mặc định là: admin  
Các option ở __Main Menu__:

| Lựa chọn | Công dụng |
| -------- | --------- |
| 420      | Bắt đầu cuộc thi, các đội thi bắt đầu thi đấu, điểm số sẽ được random|
| 69       | Kết thúc cuộc thi, các đội sẽ dừng thi đấu |
| 42069    | Truy cập tới adminPanel, tại đây có thể chỉnh sửa cuộc thi, đội thi |

### Admin panel

| Choice | Function                                              |
| ------ | ----------------------------------------------------- |
| 1      | Chỉnh sửa cuộc thi (truy cập tới Event Editor)        |
| 2      | Set điểm cho đội X                                    |
| 3      | Xóa đội thi X                                         |
| 4      | Xem thông tin cuộc thi                                |
| 5      | Xem danh sách các đội thi trong cuộc thi              |
| 6      | Quản lý đội thi X (Tương tự leaderPanel)              |
| 0      | Quay lại Main Menu                                    |

### Event Editor

| Choice | Function                                              |
| ------ | ----------------------------------------------------- |
| 1      | Đổi tên cuộc thi                                      |
| 2      | Đổi tên nhà tổ chức                                   |
| 3      | Đổi ngày tổ chức                                      |
| 4      | Thay đổi trị giá giải thưởng                          |
| 5      | Thay đổi format                                       |
| 0      | Quay lại Main Menu                                    |

## For team leader

Tại Main Menu, Leader của team có thể chỉnh sửa các thông số như tên đội và các thành viên trong đội  
Lựa chọn: 6, mật khẩu là mật khẩu lúc tạo.  
> Nếu quên mật khẩu vui lòng liên hệ Admin

### leaderPanel

| Choice | Function                                              |
| ------ | ----------------------------------------------------- |
| 1      | Đổi tên nhóm                                          |
| 2      | Xem các thành viên trong đội                          |
| 3      | Xóa thành viên khỏi đội                               |
| 4      | Thêm thành viên vào đội                               |
| 5      | Đổi mật khẩu Leader                                   |
| 0      | Quay lại Main Menu                                    |

## For event holder

Mật khẩu để khởi tạo một event mới là: init
