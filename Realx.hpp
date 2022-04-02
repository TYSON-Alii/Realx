#include <iostream>
using namespace std;
template <typename i_t, typename f_t>
class realx {
	friend realx;
	friend std::ostream;
public:
	realx() = default;
	realx(const realx<i_t, f_t>&) = default;
	realx(const i_t& n) : num(n) { };
	inline constexpr operator i_t() const { return num; };
	inline constexpr auto& operator++() { num++; return *this; };
	inline constexpr auto& operator--() { num--; return *this; };
	inline constexpr auto& operator+=(const i_t& v) { num += v; return *this; };
	inline constexpr auto& operator-=(const i_t& v) { num -= v; return *this; };
	inline constexpr auto& operator/=(const i_t& v) {
		const auto& kalan = num % v;
		num /= v;
		payda *= v;
		if (kalan != 0) {
			pay *= v;
			const auto& t_pay = kalan * payda;
			payda = v * payda;
			pay += t_pay;
		};
		sadelestir();
		return *this;
	};
	inline constexpr auto& operator*=(const i_t& v) {
		num *= v;
		pay *= v;
		sadelestir();
		return *this;
	};
	inline auto& operator+=(const realx<i_t, f_t>& other) {
		num += other.num;
		if (payda == other.payda)
			pay += other.pay;
		else {
			pay *= other.payda;
			const auto& t_pay = other.pay * payda;
			payda = other.payda * payda;
			pay += t_pay;
		};
		sadelestir();
		return *this;
	};
	inline auto& operator-=(const realx<i_t, f_t>& other) {
		num -= other.num;
		if (payda == other.payda) {
			if (pay > other.pay)
				pay -= other.pay;
			else {
				pay = payda - (other.pay - pay);
				num--;
			};
		}
		else {
			pay *= other.payda;
			const auto& t_pay = other.pay * payda;
			payda = other.payda * payda;
			if (pay > other.pay)
				pay -= t_pay;
			else {
				pay = payda - (other.pay - pay);
				num--;
			};
		};
		sadelestir();
		return *this;
	};
	/*
	inline auto& operator/=(const realx<i_t, f_t>& other) {
		const auto& kalan = num % other.num;
		num /= v.;
		payda *= v;
		pay *= ;
		if (kalan != 0) {
			pay *= v;
			const auto& t_pay = kalan * payda;
			payda = v * payda;
			pay += t_pay;
		};
		sadelestir();
		return *this;
	};
	*/
	friend std::ostream& operator<<(std::ostream& os, const realx<i_t, f_t>& v) {
		return (v.pay == 0)?(os << v.num):(os << v.num << ' ' << v.pay << '/' << v.payda);
	};
private:
	void sadelestir() {
		if (pay == payda) {
			pay = 0;
			payda = 1;
			num++;
		}
		else {
			if (pay != 0 and payda % pay == 0) {
				pay = 1;
				payda = payda / pay;
			}
			else if (pay > payda) {
				const auto& kalan = pay % payda;
				const auto& t = pay / payda;
				if (kalan == 0) {
					pay = 0;
					payda = 1;
				}
				else {
					pay = kalan;
				};
				num += t;
			};
		};
	};
	i_t num = 0;
	f_t pay = 0, payda = 1;
};
using real = realx<int, unsigned short>;
