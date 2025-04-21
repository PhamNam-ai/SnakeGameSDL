# SnakeGameSDL
**Demo Game Snake SDL2 - Cơ Cấu Chương Trình**

---

**1. Giới thiệu Game Snake**

Game Snake là trò chơi cổ điển nơi người chơi điều khiển một con rắn di chuyển trên màn hình để ăn mồi và phát triển chiều dài của mình. Mục tiêu là ăn được càng nhiều mồi càng tốt mà không chạm vào tường hoặc vào chính thân mình.

---

**2. Cách chơi**

- Người chơi điều khiển con rắn bằng các phím mũi tên: Lên, Xuống, Trái, Phải.
- Mỗi khi rắn ăn được mồi, chiều dài của rắn tăng lên.
- Nếu rắn chạm vào tường hoặc vào chính thân mình, trò chơi kết thúc.
- Sau khi thua, người chơi có thể nhấn phím Enter để chơi lại từ đầu.

---

**3. Các chức năng chính của game**

- **Di chuyển rắn**: cập nhật vị trí rắn theo hướng người chơi điều khiển.
- **Ăn mồi**: khi đầu rắn chạm vào vị trí mồi, rắn dài thêm và mồi được tạo lại ở vị trí mới.
- **Va chạm**:
  - Nếu đầu rắn chạm vào tường hoặc thân rắn → Game Over.
- **Chơi lại**: nhấn Enter để reset trò chơi.
- **Nền**: sử dụng hình ảnh PNG làm nền thay vì màu xanh đơn thuần.

---

**4. Các file trong project**

- `Game.h` / `Game.cpp`: Quản lý toàn bộ vòng lặp game, xử lý sự kiện, cập nhật trạng thái và hiển thị.
- `Snake.h` / `Snake.cpp`: Quản lý thông tin và hành vi của rắn.
- `Food.h` / `Food.cpp`: Tạo mồi và vẽ mồi trên màn hình.
- `main.cpp`: Khởi tạo và chạy game.

---

**5. Yêu cầu cài đặt thư viện (dependencies)**

### Trên Linux:
```sh
sudo apt install libsdl2-2.0-0 libsdl2-image-2.0-0 libsdl2-mixer-2.0-0 libsdl2-ttf-2.0-0
```

### Trên Windows:
- Tất cả các file DLL cần thiết để game hoạt động nằm trong thư mục project.
- Đảm bảo thư viện SDL2 đã được cài đặt qua vcpkg.
- Có thể chạy trực tiếp file `.exe` sau khi build.


