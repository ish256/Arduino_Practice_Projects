---
layout: post
title: "A Post with Images"
date: 2013-05-22
excerpt: "Examples and code for displaying images in posts."
tags: [sample post, images, test]
comments: true
---

Here are some examples of what a post with images might look like. If you want to display two or three images next to each other responsively use `figure` with the appropriate `class`. Each instance of `figure` is auto-numbered and displayed in the caption.

### Figures (for images or video)

#### One Up

<figure>
	<a href="http://farm9.staticflickr.com/8426/7758832526_cc8f681e48_b.jpg"><img src="http://farm9.staticflickr.com/8426/7758832526_cc8f681e48_c.jpg"></a>
	<figcaption><a href="http://www.flickr.com/photos/80901381@N04/7758832526/" title="Morning Fog Emerging From Trees by A Guy Taking Pictures, on Flickr">Morning Fog Emerging From Trees by A Guy Taking Pictures, on Flickr</a>.</figcaption>
</figure>

Vero laborum commodo occupy. Semiotics voluptate mumblecore pug. Cosby sweater ullamco quinoa ennui assumenda, sapiente occupy delectus lo-fi. Ea fashion axe Marfa cillum aliquip. Retro Bushwick keytar cliche. Before they sold out sustainable gastropub Marfa readymade, ethical Williamsburg skateboard brunch qui consectetur gentrify semiotics. Mustache cillum irony, fingerstache magna pour-over keffiyeh tousled selfies.

#### Two Up

Apply the `half` class like so to display two images side by side that share the same caption.

{% highlight html %}
<figure class="half">
    <figcaption>Caption describing these two images.</figcaption>
</figure>
{% endhighlight %}

And you'll get something that looks like this:

<figure class="half">
	<figcaption>Two images.</figcaption>
</figure>

#### Three Up

Apply the `third` class like so to display three images side by side that share the same caption.

{% highlight html %}
<figure class="third">
	<figcaption>Caption describing these three images.</figcaption>
</figure>
{% endhighlight %}

And you'll get something that looks like this:

<figure class="third">%}
	<figcaption>Three images.</figcaption>
</figure>

### Alternative way

Another way to achieve the same result is to include `gallery` Liquid template. In this case you
don't have to write any HTML tags – just copy a small block of code, adjust the parameters (see below)
and fill the block with any number of links to images. You can mix relative and external links.

Here is the block you might want to use:

{% highlight liquid %}
{% raw %}
{% capture images %}
	http://vignette2.wikia.nocookie.net/naruto/images/9/97/Hinata.png
	http://vignette4.wikia.nocookie.net/naruto/images/7/79/Hinata_Part_II.png
	http://vignette1.wikia.nocookie.net/naruto/images/1/15/J%C5%ABho_S%C5%8Dshiken.png
{% endcapture %}
{% include gallery images=images caption="Test images" cols=3 %}
{% endraw %}
{% endhighlight %}

Parameters:

- `caption`: Sets the caption under the gallery (see `figcaption` HTML tag above);
- `cols`: Sets the number of columns of the gallery.
Available values: [1..3].

It will look something like this:

{% capture images %}
	http://vignette2.wikia.nocookie.net/naruto/images/9/97/Hinata.png
	http://vignette4.wikia.nocookie.net/naruto/images/7/79/Hinata_Part_II.png
	http://vignette1.wikia.nocookie.net/naruto/images/1/15/J%C5%ABho_S%C5%8Dshiken.png
{% endcapture %}
{% include gallery images=images caption="Test images" cols=3 %}
