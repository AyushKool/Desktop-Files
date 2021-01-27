fun main() {
    var obj = InitOrderDemo("Ayush Koul")
    var a = 4
    a.let { it + 2 }.let { println("$it") }
    // var str = "Hello World"
    // str.let { println("$it!!") }
    // println(str)
    // var strLength = str.let { "$it function".length }
    // println("strLength is $strLength") //prints strLength is 20
}

class InitOrderDemo(name: String) {
    val firstProperty = "First property: $name".also(::println)
    init {
        println("First initializer block that prints $name")
    }
    val secondProperty = "Second property: ${name.length}".let { println("$it") }
    init {
        println("Second initializer block that prints ${name.length}")
    }
}
