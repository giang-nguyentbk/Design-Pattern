# Abstract Factory
## Content
### Vietnamese
Abstract Factory: các nhà máy, sản xuất những product giống hệt nhau, chỉ khác nhau về mặt mẫu mã. Vì vậy Abstract Factory giống như một nhà máy chung chung, sẽ sản xuất ra những product như vậy, còn việc mẫu mã như thế nào sẽ do những class con kế thừa Abstract Factory qui định.

VD: cùng những product giống nhau là bánh xe, khung xe, nội thất xe, nhưng các factories Mercedes, Toyota, Vinfast, Tesla,... sẽ thiết kế ra những mẫu mã khác nhau.

Từ đây: Ý tưởng là ta sẽ tạo ra một class Abstract Factory có các interface để tạo ra các product. Những subclass như Mercedes, Toyota,.. sẽ implement các interface đó, và sẽ tự định nghĩa các interface để tạo ra những product theo kiểu dáng, mẫu mã của riêng mình.

### English
Imagine that you're having factories which produce same products and just differ about the models or styles. So Abstract Factory looks like a generic factory which produce the products, while the model or style will be determined by the subclasses that inherit Abstract Factory.

Example: With the same products like wheels, chassis, car furniture, but factories like Mercedes, Toyota, Vinfast, Tesla, ... will design different models or styles.

To sum up: The idea is that we will create an Abstract Factory class that has interfaces to create products. Subclasses like Mercedes, Toyota,... will implement those interfaces, and will define interfaces by themselves to create products, according to their own designs and models.