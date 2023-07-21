# Hannah's Ferris Sweep Layout v3

This is the third iteration of my  first attempt at a layout for my new Ferris
Sweep. I am attempting to integrate Colemak DH, which is new to me, and keep
everything else as familiar as possible, so I have tried to take my cues for
numbers and symbols from the UK ISO keyboard layout that I am familiar with.

Broadly speaking, this is designed as a layout where keys and modifiers are
tapped rather than held down. Aside from homerow modifiers, there is no chording
or comboing. In practice, a single tap of the layer key gets to the symbol layer
and a double tap of the layer key gets to the numbers and navigation layer. Most
of the time you will be tapping the layer key once, hitting a symbol then
carrying on in the base layer.

The number and navigation layer is sticky to allow for the extended entry of
numbers and extended navigation. The function layer is technically sticky but
most of the keys will return to the number or base layer when tapped.

## Base Layer

![Base Layer](https://i.imgur.com/vcj6LgG.png)

The base layer uses Colemak DH 2020 with `shift` on the outside left thumb key,
`space` on the inside left thumb key, `enter` on the inside right thumb key and
`sym layer` on the outside right thumb key. The `backspace` key is available at
the top right. When tapped, `shift` key that will capitalise or shift the next
key that is tapped. It does nothing when held down. Similarly, the `sym layer`
key will switch to the symbol layer and return to the base layer immediately
after a single symbol key has been tapped.

Homerow modifiers are available on the following keys:

* Hold `A` or `O` for `shift`
* Hold `R` or `I` for `control`
* Hold `S` or `E` for `alt`
* Hold `T` or `N` for `win` / `cmd`

Tap dance is enabled and double taps on the following keys produce different key
presses:

* Double tapping the `Q` key produces `Esc`
* Double tapping the `Z` key produces `Caps Lock`
* Double tapping the `X` key produces `Control-X` (i.e. cut)
* Double tapping the `C` key produces `Control-V` (i.e. copy)
* Double tapping the `V` key produces `Control-C` (i.e. paste)

This reduces the need to hold the homerow modifiers down and press additional
keys.

## Symbol Layer

![Symbol Layer](https://i.imgur.com/xQuMMJ9.png)

The symbol layer is influenced by the layout of symbols on UK ISO keyboards. The
`grave` and `tab` keys are on the left hand side and the symbols usually found
above `2` to `8` are on the top row. The `minus` / `underscore` and `equals` /
`plus` are on the right hand side as pairs of separate keys situated above and
below each other.

In the middle there are similar pairs of keys that are usually found to the
right of the middle row: `hash` / `tilde` , `quote` / `at`  and `semicolon` /
`colon`. On the bottom right there is the `exclamation mark` key that would have
appeared above the number one position if there was space, but which is now
placed on the same key as the `slash` / `question mark` in the base layer. The
`backslash` / `pipe` key pair is on the far left and taking up the rest of the
left side there are pairs of braces and brackets.

The `shift` and `enter` keys remain on the inside left and right thumb keys. The
outside left thumb key, `base layer`, returns to the base layer. `num layer` on
the outside right thumb key goes to the number and navigation layer and `func
layer` at the bottom left goes to the function layer.

## Number and Navigation Layer

![Number and Navigation Layer](https://i.imgur.com/uP7fdmD.png)

Numbers appear along the top row as they do on standard sized keyboards. As with
the base layer, the top left key is a tap dance key that will produce `Esc` if
it is double tapped.

On the right side the navigation keys are arranged on the traditional Vim
navigation key locations (`hjkl` in QWERTY keyboards) with the `home`, `page
down`, `page up` and `end` keys below them. The `delete` and `insert` keys are
on the far right.

On the bottom left the `func layer` key goes to the function layer. The 'left
button' and 'right button' keys serve as alternative mouse button keys when
using an external trackball or trackpad. The final keys on the left side are Vim
shortcuts: `capital-v` to enter visual mode and `colon` to enter cmdline mode.

The thumb keys remain consistent: `shift` and `enter` on the inside keys and
`base layer` on the outside left thumb key. All three of these keys return to
the base layer.

## Function Layer

![Function Layer](https://i.imgur.com/JxCdlGP.png)

Taking up most of the left side of the function layer are twelve function keys.
When these keys are tapped the keyboard returns to the base layer immediately.

On the inside of the left side are media controls. These keys are sticky so
music tracks can be skipped, played and paused without the layer changing.

On the inside of the right side are the screen brightness and volume adjustment
keys. The rest of the right side of the keyboard has a number of symbols that
can be used in conjunction with the number layer to perform calculations. When
any of these symbols are tapped the keyboard will return to the number layer.
This is intended to simplify working with a calculator. The positions of the
symbols mirror their positions in the symbol layer.

Again the thumb keys remain consistent: `shift` and `enter` on the inside keys
and `base layer` on the outside left thumb key. All three of these keys return
to the base layer.

##  Compile and Flash the Firmware

First compile the firmware as normal:

```shell
$ qmk compile -kb ferris/sweep -km hbmorrisonv3
```

Then convert it for rp2040 controller by running:

```shell
$ make CONVERT_TO=kb2040 ferris/sweep:default:uf2-split-left
```

The make command will wait for the keyboard bootloader. Unplug the USB cable
from the Ferris Sweep, hold down the top left key and while holding the key down
plug the USB cable back into the **left-hand side** controller on the keyboard.
