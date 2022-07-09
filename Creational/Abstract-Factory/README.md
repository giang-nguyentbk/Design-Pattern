# Abstract Factory
## Content
### Vietnamese
Abstract Factory: các nhà máy, sản xuất những product giống hệt nhau, chỉ khác nhau về mặt mẫu mã. Vì vậy Abstract Factory giống như một nhà máy chung chung, sẽ sản xuất ra những product như vậy, còn việc mẫu mã như thế nào sẽ do những class con kế thừa Abstract Factory qui định.

VD1: cùng những product giống nhau là bánh xe, khung xe, nội thất xe, nhưng các factories Mercedes, Toyota, Vinfast, Tesla,... sẽ thiết kế ra những mẫu mã khác nhau.

VD2: trong một ứng dụng GUI cross-platform, có 3 control là Button, Textbox và Chart đóng vai trò là các product. Tuy nhiên, với nền tảng Windows các product sẽ có style là các góc nhọn, vuông vắn, trong khi nền tảng MAC thì các product lại có style là các góc bo tròn, mềm mại hơn. Ở đây, Windows và MAC sẽ là 2 factories chuyên sản xuất ra 3 control kể trên nhưng với mẫu mã khác nhau.

Từ đây: Ý tưởng là ta sẽ tạo ra một class Abstract Factory có các interface để tạo ra các product. Những subclass như Mercedes, Toyota,.. sẽ implement các interface đó, và sẽ tự định nghĩa các interface để tạo ra những product theo kiểu dáng, mẫu mã của riêng mình.

### English
Imagine that you're having factories which produce same products and just differ in model or style. So Abstract Factory looks like a generic factory which produce the products, while the model or style will be determined by the subclasses that inherit Abstract Factory.

Example 1: With the same products like wheels, chassis, car furniture, but factories like Mercedes, Toyota, Vinfast, Tesla, ... will design different models or styles.

Example 2: In a cross-platform GUI application, we will have 3 controls such as Button, Textbox and Chart which play a role as products. However, for Windows platform, products tend to sharp corners, whereas for MAC platform, products usually have rounded corners. So, Windows and MAC will represent factories which produce 3 above controls and just differ in corner style.

To sum up: The idea is that we will create an Abstract Factory class that has interfaces to create products. Subclasses like Mercedes, Toyota,... will implement those interfaces, and will define interfaces by themselves to create products, according to their own designs and models.