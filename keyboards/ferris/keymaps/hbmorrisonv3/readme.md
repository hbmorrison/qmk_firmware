# Hannah's Ferris Sweep Layout v3

This is the third iteration of my  first attempt at a layout for my new Ferris
Sweep. I am attempting to integrate Colemak DH, which is new to me, and keep
everything else as familiar as possible, so I have tried to take my cues for
numbers and symbols from the UK ISO keyboard layout that I am familiar with.

Broadly speaking, this is designed as a layout where keys and modifiers are
tapped rather than held down. Aside from homerow modifiers, there is no chording
or comboing. In practice, a single tap of the layer key gets to the symbol layer
and a double tap of the layer key gets to the number layer. Most of the time you
will be tapping the layer key once, hitting a symbol then carrying on in the
base layer.

## Base Layer

![Base Layer](https://i.imgur.com/vcj6LgG.png)

The base layer uses Colemak DH 2020 with `shift` on the outside left thumb key,
`space` on the inside left thumb key, `enter` on the inside right thumb key and
`sym layer` on the outside right thumb key. The `backspace` key is available at
the top right.

When tapped, the `shift` key capitalises or shifts the next key that is tapped.
It does nothing when held down. The `sym layer` key switches the keyboard into
the **symbol layer** for one key press only, and the keyboard will return to the
**base layer** immediately after a symbol key has been tapped.

Homerow modifiers are available on the following keys:

* Hold `A` or `O` for `shift`
* Hold `R` or `I` for `control`
* Hold `S` or `E` for `alt`
* Hold `T` or `N` for `win` / `cmd`

Tap dance is enabled and double taps on the following keys produce different key
presses:

* Double tapping the `Q` key produces `esc`
* Double tapping the `Z` key produces `caps lock`
* Double tapping the `X` key produces `control-X` (i.e. cut)
* Double tapping the `C` key produces `control-V` (i.e. copy)
* Double tapping the `V` key produces `control-C` (i.e. paste)

## Symbol Layer

![Symbol Layer](https://i.imgur.com/xQuMMJ9.png)

The **symbol layer** is influenced by the layout of symbols on UK ISO keyboards.
The `grave` and `tab` keys are on the left hand side and the symbols usually
found above `2` to `8` are on the top row. The `minus` / `underscore` and
`equals` / `plus` are on the right hand side as pairs of separate keys situated
above and below each other.

In the middle there are similar pairs of keys that are usually found to the
right of the middle row: `hash` / `tilde` , `quote` / `at`  and `semicolon` /
`colon`. On the bottom right there is the `exclamation mark` key that would have
appeared above the number one position if there was space, but which is now
placed on the same key as the `slash` / `question mark` in the base layer. The
`backslash` / `pipe` key pair is on the far left and taking up the rest of the
left side there are pairs of braces and brackets. The `func layer` key at the
bottom left will switch the keyboard into the **function layer**.

The `num layer` key on the outside right thumb key switches the keyboard into
the **number layer**. The `shift` and `enter` keys remain on the inside left and
right thumb keys and the outside left thumb key becomes `base layer`, which
returns the keyboard to the **base layer**. As well as emitting their key
presses, the `space` and `enter` keys will also return the keyboard to the
**base layer** when tapped.

## Number Layer

![Number Layer](https://i.imgur.com/uP7fdmD.png)

Numbers appear along the top row as they do on standard sized keyboards. As with
the base layer, the top left key is a tap dance key that will produce `esc` if
it is double tapped.

On the right side the navigation keys are arranged on the traditional Vim
navigation key locations (`hjkl` in QWERTY keyboards) with the `home`, `page
down`, `page up` and `end` keys below them. The `delete` and `insert` keys are
on the far right.

On the bottom left the `func layer` key switches the keyboard into the
**function layer**. The `left button` and `right button` keys serve as
alternative mouse buttons when using an external trackball or trackpad.

There are a set of `tab` keys on the left hand side for navigating between tabs
and windows: `control-tab`, `alt-tab` and `win/cmd-tab`.

The final keys on the left side are Vim shortcuts: `capital-V` to enter visual
mode and `colon` to enter cmdline mode.

The thumb keys remain consistent: `shift` and `enter` on the inside keys and
`base layer` on the outside left thumb key. All three of these keys return the
keyboard to the **base layer**.

## Function Layer

![Function Layer](https://i.imgur.com/JxCdlGP.png)

Twelve function keys take up most of the left side. When any of the function
keys are tapped the keyboard returns to the **base layer**.

Media controls are on the inside of the left side. These keys are sticky so
music tracks can be skipped, played and paused without the layer changing.
Screen brightness and volume adjustment keys are on the inside of the right
side. These keys are also sticky so they can be pressed repeatedly.

The rest of the right side has a number of symbols that can be used in
conjunction with the number layer to perform calculations. When any of these
symbols are tapped the keyboard will return to the **number layer**. This is
intended to simplify working with a calculator. The positions of the symbols
mirror their positions in lower layers.

Again the thumb keys remain consistent: `shift` and `enter` on the inside keys
and `base layer` on the outside left thumb key. All three of these keys return
the keyboard to the **base layer**.

##  How To Compile and Flash the Firmware

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
