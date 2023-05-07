 # Catch and Dodge
 Đây là 1 game hứng các vật phẩm tiền để tăng điểm và né những trái bom để không bị mất mạng,
 # Tổng quan
 Mỗi 1 lần chơi sẽ có 3 mạng, sau khi lên 1 lever nếu số mạng nhỏ hơn 3 sẽ được cộng 1 mạng vào lever tiếp theo.
 Nhân vật sẽ được cộng 100 điểm sau khi chạm vào các vật phẩm tiền vàng,
 Nhân vật sẽ bị trừ 100 điểm và 1 mạng sau khi chạm vào bom,(khi được khiên bảo vệ sẽ không bị trừ gì).
 Nhân vật sẽ bị trừ 500 điểm và 1 mạng sau khi bị ong đốt.(khiên không có tác dụng)
 # Cách chơi
 ## Ở màn hình đăng nhập:
 ![HDdangNhap](https://user-images.githubusercontent.com/81307877/236659597-47312e83-171c-4334-add6-93d2c1f32df7.png)
 -Tên người chơi không quá 12 kí tự, chứ kí tự đặc biệt,dấu câu.
## Ở trong trò chơi:
![hdTrongGame](https://user-images.githubusercontent.com/81307877/236659680-144f2cf8-160c-4ece-814a-cccd9557300a.png)
 Người chơi sẽ điều khiên nhân vật bằng cách sử dụng các phím sau:
 - Nhấn phím ( A vs D ) hoặc phím ( LEFT và RIGHT ) để điều khiển nhân vật chạy sang trái hoặc sang phải.
 - Nhấn phím ( Q vs E ) để sử dụng skin tốc biến từ mọi vị trí đến đầu hoặc cuối map.
 - Nhấn phím ( B ) để sử dụng khiên 
    + Khiên chỉ bảo vệ nhân vật miễn sát thương với những trái bom.
    + Với boss ong vàng khiên vẫn bị dính sát thương như bình thường. 
- Nhấn phím ( SPACE ) để nhân vật nhảy lên.
# Cách cài đặt (ở dưỡng dẫn này sử dụng visual studio code trong windows)
## Ở trong repositories này khi tải xuống đã có file 'main.exe' bạn chỉ cần chạy file này.
## Nếu bạn muốn biên dịch lại chương trình thì đây là hướng dẫn
** Bước 1 **: 
-Cài đặt [`Mingw-W64`] (https://sourceforge.net/projects/mingw-w64/files/).(Nếu chưa có )
-Cài đặt [`GNU make`] (https://stackoverflow.com/a/57042516/21271990).(Nếu chưa có)
** Bước 2 **: Sử dụng lệnh` Mingw32-make` để biên dịch chương trình.
** Bước 3 **: Sử dụng lệnh`.\main ` để chạy game.