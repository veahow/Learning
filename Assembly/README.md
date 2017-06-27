# Learning/Assembly
此文件夹存放汇编语言代码，编程模型为Intel 8086 CPU。
Intel 8086 CPU拥有数据总线所能传输位数为16位，地址总线为20位，可寻址1MB内存空间。
## 8086CPU 基本组成
* Bus Interface Unit 总线接口部件 BIU
    * 16位段寄存器 Segment 
        * Code Segment 代码段寄存器 CS
	    * Data Segment 数据段寄存器 DS
	    * Stack Segment 堆栈段寄存器 SS
	    * Extra Segment 附加段寄存器 ES
	* Instruction Pointer 16位指令指针寄存器 IP
	* 20位物理地址加法器
	* 6字节指令队列
	* 总线控制逻辑
	    * Address Bus 20位地址总线 AB
		* Control Bus 控制总线 CB
	    * Data Bus 16位数据总线 DB
* Execution Unit 指令执行部件 EU
    * Arithmetic Logic Unit 算术逻辑单元 ALU
	* 标志位寄存器 PSW or Flags
	    * 6个状态标志位
            * Carry Flag 进位标志位 CF
	        * Parity 奇偶校验标志位 PF
	        * Auxiliary Carry Flag 辅助进位标志位 AF
	        * Zero Flag 全零标志位 ZF
	        * Sign Flag 符号标志位 SF
	        * Overflow Flag 溢出标志位 OF
        * 3个控制标志位
		    * Trap Flag 单步标志位 TF
			* Interrupt Flag 中断标志位 IF
			* Ditection Flag 方向标志位 DF
	* 通用寄存器
        * Accumulator 累加器 AX
	    * Base 基址寄存器 BX
	    * Counter 计数器 CX
	    * Data 数据寄存器 DX
    * 指针及变址寄存器
        * Stack Pointer 堆栈指针寄存器 SP
	    * Base Pointer 基址指针寄存器 BP
	    * Source Index 源变址寄存器 SI
	    * Destination Index 目的变址寄存器 DI
    * EU控制器

