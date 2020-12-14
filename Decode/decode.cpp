/* Strategy: Decode the instruction, registers, control signal values, and
             stages separately using functions, then combine them at the end.
*/

//Aaron Meche

#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;

int binarystr_to_int(string s);
int binarystr_to_int_jump(string s);

// these #defines define the 6 bit string representing the op code
#define ADDI    "001000"
#define BEQ     "000100"
#define JUMP    "000010"
#define LW      "100011"
#define SW      "101011"
#define R_TYPE  "000000"

// in the case where the op code is an R type, these #defines define the bits that
// indicate which instruction the R type is
#define SUB     "00000100010"
#define SLT     "00000101010"
#define ADD     "00000100000"

enum Op_Code {add, addi, sub, beq, slt, jump, lw, sw, error }; //set up enumerator for the instructions as Op_code

string s_reg = "";  //initializing global strings
string t_reg = "";
string d_reg = "";
string immediate = "";

/******************************************************************************
Function: decode_instruction
Input:
    A 32 bit string representing the machine instruction
    in big endian
Output:
    An string that designates the instruction.
Logic:
    The function takes a string, looks at the first 6 bits, and outputs an
    integer that designates what the instruction is. I am using string r as
    a string full of 0's to compare to the first 6 bits in the instruction.
    If the comparison passes, check to see if the instruction is add, sub,
    or slt. Check the other instructions using else-if.
*******************************************************************************/

Op_Code decode_instruction(string machineInstruction)
{
    // the op code portion of the machine instruction is the first 6 characters
    // of the 32 bit binary number, so first get those
    string opcode_substr = machineInstruction.substr(0,6);
    string rtype_substr  = machineInstruction.substr(21,11);

    Op_Code opcode;

    if(opcode_substr.compare(ADDI) == 0) {
        opcode = addi;
    }
    else if(opcode_substr.compare(BEQ) == 0) {
        opcode = beq;
    }
    else if(opcode_substr.compare(JUMP) == 0) {
        opcode = jump;
    }
    else if(opcode_substr.compare(LW) == 0) {
        opcode = lw;
    }
    else if(opcode_substr.compare(SW) == 0) {
        opcode = sw;
    }
    else if(opcode_substr.compare(R_TYPE) == 0) {
        if(rtype_substr.compare(SUB) == 0) {
            opcode = sub;
        }
        else if(rtype_substr.compare(ADD) == 0) {
            opcode = add;
        }
        else if(rtype_substr.compare(SLT) == 0) {
            opcode = slt;
        }
        else {
            cout << "Error, unrecognized instruction" << endl;
            opcode = error;
        }
    }
    else {
        cout << "Error, unrecognized instruction" << endl;
        opcode = error;
    }

    return opcode;
}

/******************************************************************************
Function: opcode_to_str
Input:
    An Op_Code type that designates the instruction
Output:
    A string that has the instruction stored in it
Logic:
    The function takes an Op_Code type and returns a string that has the
    instruction stored in it.
*******************************************************************************/

string opcode_to_str(Op_Code opcode) {
    string str;
    switch(opcode) {
    case add:
        str = "add";
        break;
    case addi:
        str = "addi";
        break;
    case sub:
        str = "sub";
        break;
    case beq:
        str = "beq";
        break;
    case slt:
        str = "slt";
        break;
    case jump:
        str = "j";
        break;
    case lw:
        str = "lw";
        break;
    case sw:
        str = "sw";
        break;
    case error:
        str = "ERROR, INVALID INSTRUCTION";
        break;
    }
    return str;
}

/******************************************************************************
Function: register_int_to_name
Input:
    An integer that represents the register value.
Output:
    A string that designates the register being referenced in the integer.
Logic:
    The functions takes an integer and returns a string holding the
    corresponding register name.
*******************************************************************************/

string register_int_to_name(int reg) {
    string reg_name = "";
    switch(reg) {
    case 0:
        reg_name = "$zero";
        break;
    case 1:
        reg_name = "$at";
        break;
    case 2:
        reg_name = "$v0";
        break;
    case 3:
        reg_name = "$v1";
        break;
    case 4:
        reg_name = "$a0";
        break;
    case 5:
        reg_name = "$a1";
        break;
    case 6:
        reg_name = "$a2";
        break;
    case 7:
        reg_name = "$a3";
        break;
    case 8:
        reg_name = "$t0";
        break;
    case 9:
        reg_name = "$t1";
        break;
    case 10:
        reg_name = "$t2";
        break;
    case 11:
        reg_name = "$t3";
        break;
    case 12:
        reg_name = "$t4";
        break;
    case 13:
        reg_name = "$t5";
        break;
    case 14:
        reg_name = "$t6";
        break;
    case 15:
        reg_name = "$t7";
        break;
    case 16:
        reg_name = "$s0";
        break;
    case 17:
        reg_name = "$s1";
        break;
    case 18:
        reg_name = "$s2";
        break;
    case 19:
        reg_name = "$s3";
        break;
    case 20:
        reg_name = "$s4";
        break;
    case 21:
        reg_name = "$s5";
        break;
    case 22:
        reg_name = "$s6";
        break;
    case 23:
        reg_name = "$s7";
        break;
    case 24:
        reg_name = "$t8";
        break;
    case 25:
        reg_name = "$t9";
        break;
    case 26:
        reg_name = "$k0";
        break;
    case 27:
        reg_name = "$k1";
        break;
    case 28:
        reg_name = "$gp";
        break;
    case 29:
        reg_name = "$sp";
        break;
    case 30:
        reg_name = "$fp";
        break;
    case 31:
        reg_name = "$ra";
        break;
    default:
        break;

    }

    return reg_name;
}

/******************************************************************************
Function: print_std_registers
Input:
    A string that holds the instruction.
Output:
    N/A
Logic:
    The functions takes a 32 bit string that designates the machine instruction,
    stores the values at the register ranges as substrings, calculates the
    values of the registers, prints each register value, and then stores the register
    names into s_reg, t_reg, and d_reg. This is for printing the R-type instructions
    that use 3 registers.
*******************************************************************************/

void print_std_registers(string machineInstruction) {
    string s_register = machineInstruction.substr(6,5);
    string t_register = machineInstruction.substr(11, 5);
    string d_register = machineInstruction.substr(16, 5);

    int s_register_int = binarystr_to_int(s_register);
    int t_register_int = binarystr_to_int(t_register);
    int d_register_int = binarystr_to_int(d_register);

    cout << "s register: " << s_register_int << endl;
    cout << "t_register: " << t_register_int << endl;
    cout << "d_register: " << d_register_int << endl;

    s_reg = register_int_to_name(s_register_int);
    t_reg = register_int_to_name(t_register_int);
    d_reg = register_int_to_name(d_register_int);

}

/******************************************************************************
Function: print_st_registers
Input:
    A string that holds the instruction.
Output:
    N/A
Logic:
    The functions takes a 32 bit string that designates the machine instruction,
    stores the values at the register ranges as substrings, calculates the
    values of the registers, prints each register value, and then stores the register
    names into s_reg and t_reg. This is for printing the instructions that only
    use 2 registers.
*******************************************************************************/

void print_st_registers(string machineInstruction) {
    string s_register = machineInstruction.substr(6,5);
    string t_register = machineInstruction.substr(11, 5);

    int s_register_int = binarystr_to_int(s_register);
    int t_register_int = binarystr_to_int(t_register);

    cout << "s_register: " << binarystr_to_int(s_register) << endl;
    cout << "t_register: " << binarystr_to_int(t_register) << endl;

    s_reg = register_int_to_name(s_register_int);
    t_reg = register_int_to_name(t_register_int);
}

/******************************************************************************
Function: print_jump
Input:
    A string that holds the instruction.
Output:
    N/A
Logic:
    The functions takes a 32 bit string that designates the machine instruction,
    calculates the value of the jump, and prints the address of the jump.
*******************************************************************************/

void print_jump(string machineInstruction) {

    int jmp = binarystr_to_int_jump(machineInstruction);

    cout << "Jump address: " << jmp << endl;
}

/******************************************************************************
Function: binarystr_to_int
Input:
    A string that holds the instruction or the register values.
Output:
    The integer value of the string.
Logic:
    The function takes a bit string of variable size that designates the machine
    instruction and register value, and converts it to an integer.
*******************************************************************************/

int binarystr_to_int(string s) {
    int factor = 1;
    int binaryInt = 0;

    for(int i = s.length()-1; i >= 0; i--) {
        if(s.at(i) == '1') {
            binaryInt += factor;
        }
        factor = factor * 2;
    }

    return binaryInt;
}

/******************************************************************************
Function: binarystr_to_int_immediate
Input:
    A string that holds the instruction immediate values.
Output:
    The integer value of the string.
Logic:
    The function takes a bit string of variable size that designates the immediate
    values for instructions like sw and lw, and converts them into integers. The
    integer output is the bit offset for these instructions.
*******************************************************************************/

int binarystr_to_int_immediate(string s) {
    int factor = 1;
    int binaryInt = 0;

    for(int i = s.length()-1; i >= 16; i--) {
        if(s.at(i) == '1') {
            binaryInt += factor;
        }
        factor = factor * 2;
    }

    return binaryInt;
}

/******************************************************************************
Function: binarystr_to_int_jump
Input:
    A string that holds the jump address
Output:
    The integer value of the string.
Logic:
    The function takes a bit string of a fixed size corresponding with the jump
    immediate value, calculates the immediate value as an integer, and returns
    it. The output is the jump address.
*******************************************************************************/

int binarystr_to_int_jump(string s) { //calculates the address for Jump instruction
    int factor = 1;
    int binaryInt = 0;

    for(int i = s.length()-1; i >= 5; i--) {
        if(s.at(i) == '1') {
            binaryInt += factor;
        }
        factor = factor * 2;
    }

    return binaryInt;
}

/******************************************************************************
Function: print_control_registers
Input:
    An Opcode type that contains the opcode.
Output:
    N/A
Logic:
    The function takes an Op_Code, determines the control signal values based on
    that opcode, sets them on a case by case basis, and then prints them.
*******************************************************************************/

void print_control_registers(Op_Code opcode) {
    cout << "Control Register Values (binary):" << endl;
    string regdst;
    string regwrite;
    string alusrc;
    string aluop;
    string memwrite;
    string memread;
    string memtoreg;
    string branch;
    switch(opcode) {
    case add:
        regdst   = "1";
        regwrite = "1";
        alusrc   = "0";
        aluop    = "010";
        memwrite = "0";
        memread  = "0";
        memtoreg = "0";
        branch   = "0";
        break;
    case sub:
        regdst   = "1";
        regwrite = "1";
        alusrc   = "0";
        aluop    = "110";
        memwrite = "0";
        memread  = "0";
        memtoreg = "0";
        branch   = "0";
        break;
    case slt:
        regdst   = "1";
        regwrite = "1";
        alusrc   = "0";
        aluop    = "111";
        memwrite = "0";
        memread  = "0";
        memtoreg = "0";
        branch   = "0";
        break;
    case addi:
        regdst   = "0";
        regwrite = "1";
        alusrc   = "1";
        aluop    = "010";
        memwrite = "0";
        memread  = "0";
        memtoreg = "0";
        branch   = "0";
        break;
    case beq:
        regdst   = "Don't Care";
        regwrite = "0";
        alusrc   = "0";
        aluop    = "110";
        memwrite = "0";
        memread  = "0";
        memtoreg = "Don't Care";
        branch   = "1";
        break;
    case lw:
        regdst   = "0";
        regwrite = "1";
        alusrc   = "1";
        aluop    = "010";
        memwrite = "0";
        memread  = "1";
        memtoreg = "1";
        branch   = "0";
        break;
    case sw:
        regdst   = "Don't Care";
        regwrite = "0";
        alusrc   = "1";
        aluop    = "010";
        memwrite = "1";
        memread  = "0";
        memtoreg = "Don't Care";
        branch   = "0";
        break;
    case jump:
        regdst   = "Don't Care";
        regwrite = "0";
        alusrc   = "1";
        aluop    = "010";
        memwrite = "1";
        memread  = "0";
        memtoreg = "Don't Care";
        branch   = "1";
        break;
    case error:
        cout << "Cannot print control registers for invalid op code" << endl;
        break;

    }

    cout << "  RegDst  : " << regdst    << endl;
    cout << "  RegWrite: " << regwrite  << endl;
    cout << "  ALUSrc  : " << alusrc    << endl;
    cout << "  ALUOp   : " << aluop     << endl;
    cout << "  MemWrite: " << memwrite  << endl;
    cout << "  MemRead : " << memread   << endl;
    cout << "  MemToReg: " << memtoreg  << endl;
    cout << "  Branch  : " << branch    << endl;
}

/******************************************************************************
Function: print_cpu_stages
Input:
    An Opcode type that contains the opcode.
Output:
    N/A
Logic:
    The function takes an Op_Code, determines the cpu stage based on
    that opcode, sets the bools to true on a case by case basis (fasle by default),
    and then prints them.
*******************************************************************************/

void print_cpu_stages(Op_Code opcode) {
    cout << "Processor stages used for instruction:" << endl;
    bool if_stage = false;
    bool id_stage = false;
    bool ex_stage = false;
    bool mm_stage = false;
    bool wb_stage = false;

    switch(opcode) {
    case add:
        if_stage = true;
	    id_stage = true;
	    ex_stage = true;
	    wb_stage = true;
        break;
    case sub:
        if_stage = true;
	    id_stage = true;
	    ex_stage = true;
	    wb_stage = true;
        break;
    case slt:
        if_stage = true;
	    id_stage = true;
	    ex_stage = true;
	    wb_stage = true;
        break;
    case addi:
        if_stage = true;
    	id_stage = true;
	    ex_stage = true;
	    wb_stage = true;
        break;
    case beq:
        if_stage = true;
	    id_stage = true;
	    ex_stage = true;
	    wb_stage = true;
        break;
    case lw:
        if_stage = true;
	    id_stage = true;
	    ex_stage = true;
	    mm_stage = true;
	    wb_stage = true;
        break;
    case sw:
        if_stage = true;
	    id_stage = true;
	    ex_stage = true;
	    mm_stage = true;
        break;
    case jump:
        if_stage = true;
	    id_stage = true;
        break;
    case error:
        cout << "Cannot print processor stages for invalid op code" << endl;
        break;

    }

    cout << "  IF  : " << if_stage << endl;
    cout << "  ID  : " << id_stage << endl;
    cout << "  EX  : " << ex_stage << endl;
    cout << "  MEM : " << mm_stage << endl;
    cout << "  WB  : " << wb_stage << endl;
}


/******************************************************************************
Main
Input:
    None
Output:
    None
Logic:
    User inputs a size 32 bit string. The custom functions take the string and
    decodes the instruction type, control signal values, register operands,
    and which stages of the processor are used. At the end, the exact assembly
    instruction input by the user is printed. I have also provided error messages
    in the print functions that describe when an invalid entry has been entered.
*******************************************************************************/
int main()
{

    int jmp = 0;
    int offset = 0;

    Op_Code opcode;
    string bit;

    cout << "Enter the 32-bit instruction below (type -1 to exit the program):" << endl;
    cin >> bit;
    cout << "32 bit instruction: " << endl;
    cout << bit << endl;

    // decode the op code from the machine instruction
    opcode = decode_instruction(bit);
    cout << "opcode: " << opcode_to_str(opcode) << endl;

    // decode the registers used based on the op code and the overall machine instruction
    switch(opcode) {
    case add:
    case sub:
    case slt:
        print_std_registers(bit);
        break;
    case addi:
    case beq:
    case lw:
    case sw:
        print_st_registers(bit);
        break;
    case jump:
        cout << "No registers are used in the jump instruction" << endl;
        break;
    case error:
        cout << "Cannot print register operands on invalid op code" << endl;
        break;
    }

    //calls print functions for the registers and cpu stages
    print_control_registers(opcode);
    print_cpu_stages(opcode);

    //prints the assembly instruction
    cout << "Assembly language instruction:" << endl;

    switch(opcode) {
    case add:
    case sub:
    case slt:
        cout << opcode_to_str(opcode) << " " << d_reg << ", " << s_reg << ", " << t_reg << endl;
        break;
    case addi:
    case beq:
        offset = binarystr_to_int_immediate(bit);
        cout << opcode_to_str(opcode) << " " << t_reg << ", " << s_reg << ", " << offset << endl;
        break;
    case lw:
    case sw:
        offset = binarystr_to_int_immediate(bit);
        cout << opcode_to_str(opcode) << " " << t_reg << ", " << offset << "(" << s_reg << ") " << endl;
        break;
    case jump:
        jmp = binarystr_to_int_jump(bit);
        cout << opcode_to_str(opcode) << " " << jmp << endl;
        break;
    case error:
        cout << "Cannot print register operands on invalid op code" << endl;
        break;
    }
    return 0;
}
