## Realx
Rasyonel kayan noktalı sayı sistemi.
```cpp
auto main() -> int {
	cout << setprecision(50);
	real num = 1000;
	cout << "real: 1000 / 7 = " << num / 7 << " size of: " << sizeof(num) << '\n';
	float num2 = 1000.f;
	cout << "f32: 1000 / 7 = " << num2 / 7 << " size of: " << sizeof(num2) << '\n';
	double num3 = 1000.0;
	cout << "f64: 1000 / 7 = " << num3 / 7 << " size of: " << sizeof(num3) << '\n';
};
/*
# OUTPUT:
real: 1000 / 7 = 142.857142.. size of: 8 // not wrong
f32: 1000 / 7 = 142.857147216796875 size of: 4 // wrong after 5 digit
f64: 1000 / 7 = 142.857142857142861203101347200572490692138671875 size of: 8 // wrong after 11 digit
*/
```
