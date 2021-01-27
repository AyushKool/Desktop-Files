fun main(args: Array<String>) {
    // var a = B()
    // var items = listOf(1, 2, 3, 4)
    A().f(object : Interface{
    })
}

open class A()
{
    fun f(i: Interface) = i.doSomething()
}

interface Interface{
    fun doSomething() = print("message")
}