# t_copydata

## `java`测试代码

``` java
package jni;

public class tmain {
	{
		System.load("D:\\demos\\t_copydata\\x64\\Debug\\t_copydata.dll");
	}

	public native void no_args_return();

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new tmain().no_args_return();
		try {
			Thread.sleep(10000);
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
```
