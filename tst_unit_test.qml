import QtQuick 2.15
import QtTest 1.0

TestCase {
    name: "CombinedTests"

    // Тест 1
    function test_case1() {
        console.log("Запуск теста 1...")
        compare(1 < 2, true, "1 должно быть меньше 2")
        verify(2 > 1)
        console.log("Тест 1 завершён успешно")
    }

    // Тест 2
    function test_TestFunctionName() {
        console.log("Запуск теста 2...")
        compare(1 < 2, true, "1 должно быть меньше 2")
        console.log("Тест 2 завершён успешно")
    }
}
