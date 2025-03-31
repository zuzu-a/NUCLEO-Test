.. _coding_conventions:

Coding Conventions
==================

This project follows a structured naming convention to improve code clarity and maintainability. Below is a reference for naming different types of variables and functions.

Variable Naming Conventions
---------------------------
The following prefixes should be used based on the variable type:

.. list-table:: Variable Naming Conventions
   :widths: 30 20 50
   :header-rows: 1

   * - **Definition**
     - **Prefix**
     - **Example**
   * - Local variable (trivial)
     - None
     - i, n, a, b
   * - Local variable (descriptive)
     - None
     - variable, connection
   * - Global variable
     - ``g_``
     - g_variable, g_connection
   * - Constant variable
     - ``c_``
     - c_variable, c_connection
   * - Pointer
     - ``p_``
     - p_variable, p_connection
   * - Array
     - ``a_``
     - a_variable, a_connection
   * - Struct
     - ``s_``
     - s_variable, s_connection
   * - Union
     - ``u_``
     - u_variable, u_connection
   * - Enum
     - ``e_``
     - e_variable, e_connection
   * - Struct member
     - ``m_``
     - m_variable, m_connection
   * - Union member
     - ``m_``
     - m_variable, m_connection
   * - Enum member
     - ``m_``
     - m_variable, m_connection
   * - Struct (bit field)
     - ``b_``
     - b_variable, b_connection
   * - Function
     - ``f_``
     - f_variable, f_connection
   * - Macro
     - ``O_`` (uppercase)
     - O_VARIABLE, O_CONNECTION

Additional Coding Guidelines
----------------------------
- **Function Naming:** Use `snake_case` for function names (e.g., `initialize_uart()`).
- **Macro Naming:** Use uppercase with underscores (e.g., `MAX_BUFFER_SIZE`).
- **Struct and Enum Naming:** Use `typedef` for defining structures, prefixed with `s_` (e.g., `typedef struct s_uart_config`).
- **Pointer Usage:** Clearly indicate pointers in function signatures and variable declarations.

By following these conventions, we ensure that the code remains readable, maintainable, and aligned with industry best practices.