.. _code_blocks:

Code Examples for STM32 Programming
===================================

This section provides structured code block examples for various C constructs used in STM32 programming.

Function Definitions
--------------------
Every function should have a Doxygen-style comment and follow standard naming conventions.

.. code-block:: c

    /**
     * @brief Initializes the system clock.
     * @return 0 on success, negative on failure.
     */
    int init_clock(void) {
        // Clock initialization logic
        return 0;
    }

Struct Definitions
------------------
Use a `typedef` for structures and prefix with `s_` for clarity.

.. code-block:: c

    /**
     * @brief UART configuration structure
     */
    typedef struct s_uart_config {
        uint32_t baud_rate;
        uint8_t parity;
        uint8_t stop_bits;
    } uart_config_t;

Enum Definitions
----------------
Enums should be prefixed with `e_` and follow a structured naming scheme.

.. code-block:: c

    /**
     * @brief Error codes for system operations
     */
    typedef enum e_system_status {
        SYSTEM_OK = 0,
        SYSTEM_ERROR = -1,
        SYSTEM_TIMEOUT = -2
    } system_status_t;

Macro Definitions
-----------------
Macros should be defined using uppercase letters and underscores.

.. code-block:: c

    #define MAX_BUFFER_SIZE 1024
    #define ENABLE_DEBUG_MODE 1

Pointer Usage
-------------
Pointers should be clearly indicated in function signatures.

.. code-block:: c

    /**
     * @brief Reads data from a buffer.
     * @param buffer Pointer to the data buffer
     * @param length Number of bytes to read
     * @return 0 on success, negative on failure
     */
    int read_buffer(uint8_t *buffer, size_t length);

Register Access and Bit Manipulation
------------------------------------
For direct hardware access, bitwise operations are commonly used.

.. code-block:: c

    #define GPIO_PORT   (*(volatile uint32_t*)0x40020000)
    #define GPIO_PIN_5  (1 << 5)

    // Set GPIO Pin 5
    GPIO_PORT |= GPIO_PIN_5;

    // Clear GPIO Pin 5
    GPIO_PORT &= ~GPIO_PIN_5;

Interrupt Service Routine (ISR)
-------------------------------
ISRs must be kept short and efficient.

.. code-block:: c

    void EXTI0_IRQHandler(void) {
        if (EXTI->PR & EXTI_PR_PR0) {
            // Clear pending bit
            EXTI->PR |= EXTI_PR_PR0;

            // Handle the interrupt event
        }
    }

This section serves as a quick reference for proper STM32 coding practices. Following these conventions will ensure maintainability and consistency across the project.
