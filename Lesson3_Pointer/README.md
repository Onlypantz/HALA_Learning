
# Lesson 3: Con trỏ (Pointer) 

## 1. Khái niệm
Con trỏ là một biến dùng để lưu giá trị địa chỉ một đối tượng (biến, hàm, con trỏ,...).
### 1.1 Cách khai báo 
    <datatype> *<tên biến>; 

Lưu ý: khi khai báo pointer nên khởi tạo giá trị (Pointer Initialization), tránh pointer trỏ vào vùng địa chỉ không xác định.

    int a;
    int *ptr = &a;
Cách truy cập giá trị của địa chỉ lưu trong con trỏ (Pointer Dereference)

    int b = *ptr;  // gán giá trị được lưu trong địa chỉ vùng nhớ được trỏ đến bởi "ptr" cho "b"
Kích thước con trỏ phụ thuộc vào kiến trúc máy tính và trình biên dịch

    int size_ptr = sizeof(ptr);
size_ptr = 4 bytes nếu 32Bit-System
size_ptr = 8 bytes nếu 64Bit-System   
### 1.2 Các kiểu con trỏ
#### 1.2.1. Con trỏ trỏ đến hằng (Pointer to Const)
    const <datatype> *<tên biến>;
Đây là dạng con trỏ thường dùng để trỏ đến vùng nhớ read-only (con trỏ không thể thay đổi giá trị của vùng nhớ trỏ tới, chỉ có thể thay đổi địa chỉ trỏ tới)

    int a = 10;
    int b = 15;
    const int *ptr_1 = &a;
    *ptr_1 = 5;         // Error
    ptr_1 = &b;         // OK

#### 1.2.2. Hằng con trỏ (Const pointer)
    <datatype> const *<tên biến>;
Đây là dạng con trỏ thường dùng để trỏ đến địa chỉ các thanh ghi để thay đổi giá trị được lưu trong vùng nhớ thanh ghi đó (con trỏ không thể thay đổi địa chỉ con trỏ trỏ vào, chỉ có thể thay đổi giá trị được lưu trong vùng nhớ)

    int a = 10;
    int b = 15;
    int const *ptr_1 = &a;
    *ptr_1 = 5;         // OK
    ptr_1 = &b;         // Error 

#### 1.2.3. Con trỏ trỏ đến mảng (Array Pointer / Pointer to Array)
    <datatype> (*<tên biến>)[số lượng phần tử mảng];

Chú ý: con trỏ trỏ đên mảng khác với con trỏ trỏ đến phần tử đầu tiên trong mảng.

    int arr [5];
    int *ptr = arr;                  // Con trỏ ptr trỏ đến phần tử đầu tiên trong mảng arr là arr[0]
    int (*ptr_to_arr)[5] = &arr;     // Con trỏ ptr_to_arr trỏ đến tất cả 5 phần tử trong mảng arr

    // In địa chỉ được lưu trong con trỏ
    printf ("ptr = %p, ptr_to_arr = %p \n", ptr, ptr_to_arr);

    ptr++;
    ptr_to_arr++;

    // In địa chỉ được lưu trong con trỏ
    printf ("ptr = %p, ptr_to_arr = %p \n", ptr, ptr_to_arr);
Kết quả: (giả sử địa chỉ arr[0] = 0x0u), 32bit-System


    ptr = 0x0, ptr_to_arr = 0x0
    ptr = 0x4, ptr_to_arr = 0x14

#### 1.2.4. Con trỏ struct (Structure Pointer)
    struct <tên struct> *<tên biến>;
Ví dụ:

    struct people  
    {
        unsigned int age;
        char name[50];
        char sex[10];
    }p;
    int main ()
    {
        struct people *ptr_people = &p;     // Khai báo con trỏ ptr_people trỏ đến struct people 
        return 0;
    }
Cách truy cập member trong struct bằng con structure pointer:

    1. Sử dụng toán tử * và .
    2. Sử dụng toán tử ->
Ví dụ:

    struct people  
    {
        unsigned int age;
        char name[50];
        char sex[10];
    }p;
    int main ()
    {
        struct people *ptr_people = &p;     // Khai báo con trỏ ptr_people trỏ đến struct people 

        // Sử dụng * và .
        (*ptr_people).age = 18;
        printf ("Age: %d \n", (*ptr_people).age);
        
        // Sử dụng toán tử ->
        ptr_people -> age =18;
        printf ("Age: %d \n", (*ptr_people).age);

        return 0;
    }
#### 1.2.5. Con trỏ trỏ đến hàm (Function Pointer)
    <datatype> (*tên biến) (<datatype>,...)
Ví dụ:

    int sum (int a, int b)
    {
        return a+b;
    }
    int main ()
    {
        int a = 5;
        int b = 10;
        int (*ptr)(int, int) = &sum;

        printf ("%d + %d = %d", a, b, (*ptr)(a,b));

        return 0;
    }
Lưu ý:

+ Không giống như normal poiner, Function Pointer trỏ đến code, không phải data.
+ Function's name cũng được sử dụng để lấy Function's address. Do đó, ta có thể loại bỏ toán tử & khi gán function cho pointer, và * khi tham chiếu dữ liệu đến pointer

Ví dụ:

        int main ()
    {
        int a = 5;
        int b = 10;
        int (*ptr)(int, int) = sum;                 // OK

        printf ("%d + %d = %d", a, b, *ptr(a,b));   // OK 

        return 0;
    }
#### 1.2.6. Con trỏ trỏ đến con trỏ (Pointer to Pointer)
    <datatype> **<tên biến>;
Cách dereference pointer:

    *<tên biến>;     // lấy địa chỉ của con trỏ được trỏ đến
    **<tên biến>;    // lấy giá trị của được lưu trong vùng nhớ mà con trỏ được trỏ đến
Ví dụ:

    int main ()
    {
        int a = 10;           // Giả sử địa chỉ của a là 0x00 
        int *ptr = &a         // Giả sử địa chỉ của con trỏ ptr là 0x20
        int **pptr = &ptr;    // Giả sử địa chỉ của con trỏ pptr là 0x40 

        printf ("a = %d, address of a = %p\n", a, &a);
        printf ("value which ptr pointing is: %d, ptr = %p, address of ptr = %p\n", *ptr, ptr, &ptr);
        printf ("address which pptr pointing is: %p, pptr = %p, address of pptr = %p\n",*pptr, pptr, &pptr);

        return 0;
    }
Kết quả

    a = 10, address of a = 0x00
    value which ptr pointing is: 10, ptr = 0x00, address of ptr = 0x20
    address which pptr pointing is: 0x00, pptr = 0x20, address of pptr = 0x40
#### 1.2.7. Void Pointer
Là con trỏ có kiểu dữ liệu void. Void pointer có thể giữ địa chỉ của bất kì kiểu dữ liệu nào và cũng có thể ép kiểu thành bất kì kiểu dữ liệu nào.

    void *<tên biến>;
Void pointer không thể dereference. Muốn dereference, ta cần ép kiểu về datatype tương ứng.

    int main ()
    {
        int a = 0;
        char c = 'n';
        void *ptr = &a;   // OK
        ptr = &c;          //OK

        printf ("%s \n", *ptr);         // Error: 'void*' is not a pointer-to-object type
        printf ("%s \n", *(char*)ptr);  //OK 
        
        return 0;
    } 
#### 1.2.8. NULL Pointer
Là con trỏ không trỏ đến vùng nhớ nào. Được tạo ra bằng cách gán giá trị NULL cho con trỏ.

    <datatype> *<tên biến> = NULL;

Các trường hợp thường sử dụng NULL Pointer

+ Khởi tạo pointer
+ Kiểm tra lỗi con trỏ trỏ đến NULL trước khi thực hiện các phép toán liên quan đến con trỏ.
+ Trong function khi không có nhu cầu thao tác trên con trỏ nào đó, người ta thường gán cho nó là NULL. 