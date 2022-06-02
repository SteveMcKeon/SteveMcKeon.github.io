---
layout: page
title: Test File
---

This is a demo.

|Don't Branch|Take Branch|Don't Branch|Take Branch|input0 bits|input1 bits|
|:----:|:----:|:----:|:----:|:----:|:----:|
|(input0 & 0x80) == 0| | |(input1 & 0x80) == 0|1|0|
| |(input0 & 0x40) == 0|(input1 & 0x40) == 0| |0|1|
|(input0 & 0x20) == 0| | |(input1 & 0x20) == 0|1|0|
| |(input0 & 0x10) == 0| |(input1 & 0x10) == 0|0|0|
| |(input0 & 8) == 0|(input1 & 8) == 0| |0|1|
| |(input0 & 4) == 0|(input1 & 4) == 0| |0|1|
|(input0 & 2) == 0| |(input1 & 2) == 0| |1|1|
|(input0 & 1) == 0| | |(input1 & 1) == 0|1|0|

**Here is some bold text**

## Here is a secondary heading

Here's a useless table:

| Number | Next number | Previous number |
| :------ |:--- | :--- |
| Five | Six | Four |
| Ten | Eleven | Nine |
| Seven | Eight | Six |
| Two | Three | One |


How about a yummy crepe?

![Crepe](https://s3-media3.fl.yelpcdn.com/bphoto/cQ1Yoa75m2yUFFbY2xwuqw/348s.jpg)

It can also be centered!

![Crepe](https://s3-media3.fl.yelpcdn.com/bphoto/cQ1Yoa75m2yUFFbY2xwuqw/348s.jpg){: .mx-auto.d-block.rounded-circle.img-thumbnail :}

Here's a code chunk:

~~~
var foo = function(x) {
  return(x + 5);
}
foo(3)
~~~

And here is the same code with syntax highlighting:

```javascript
var foo = function(x) {
  return(x + 5);
}
foo(3)
```

And here is the same code yet again but with line numbers:

{% highlight javascript linenos %}
var foo = function(x) {
  return(x + 5);
}
foo(3)
{% endhighlight %}

## Boxes
You can add notification, warning and error boxes like this:

### Notification

{: .box-note}
**Note:** This is a notification box.

### Warning

{: .box-warning}
**Warning:** This is a warning box.

### Error

{: .box-error}
**Error:** This is an error box.
