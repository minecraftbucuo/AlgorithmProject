#include <bits/stdc++.h>
using namespace std;

// 读取 __int128 类型输入的函数
__int128 read() {
	__int128 X = 0;  // 初始化结果变量
	__int128 w = 1;  // 符号位，默认为正数

	char ch = getchar(); // 读取第一个字符

	// 跳过非数字字符（处理前导空白和符号）
	while (ch < '0' || ch > '9') {
		// 遇到负号时设置负值标志
		if (ch == '-') w = -1;
		ch = getchar();  // 继续读取字符
	}

	// 处理数字部分
	while (ch >= '0' && ch <= '9') {
		// 相当于 X = X * 10 + (ch - '0')
		// 位运算优化：X << 3 = X*8, X << 1 = X*2 -> 合计 X*10
		X = (X << 3) + (X << 1) + (ch - '0');
		ch = getchar();  // 继续读取字符
	}
	return w * X;  // 应用符号位
}

// 递归辅助函数，用于实际输出（无符号处理）
void write_(__int128 a) {
	if (a) {  // 递归终止条件：当a变为0时停止
		write_(a / 10);  // 先递归处理更高位数
		putchar(a % 10 + '0');  // 输出当前最低位数字
	}
}

// 主输出函数（处理零值、符号和递归调用）
void write(__int128 a) {
	if (a == 0) {
		putchar('0');  // 特殊情况：直接输出0
	} else if (a > 0) {
		write_(a);  // 正数直接调用递归输出
	} else {
		putchar('-');  // 负数先输出负号
		write_(-a);   // 将负数转为正数后递归输出
	}
}

int main() {
	__int128 a = read();
	__int128 b = read();
	write(a * b);
	return 0;
}
