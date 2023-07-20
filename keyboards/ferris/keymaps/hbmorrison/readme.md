# Hannah's Ferris Sweep Layout

This is my first attempt at a layout for my new Ferris Scoop. I am attempting to
integrate Colemak DH, which is new to me, and keep everything else as familiar
as possible, so I have tried to take my cues for numbers and symbols from the UK
ISO keyboard layout that I know.

Broadly speaking, this is designed to be a one-shot layout. The base layer has a
one-shot shift key on the left thumb and one-shot layer change to layer one on
the right thumb so most of the time will be spent in the base layer and, aside
from the homerow modifiers, there is no chording or comboing.

In practice, a single tap of the layer key gets to the symbol layer and a double
tap of the layer key gets to the navigation and numeral layer. Most of the time
you will be tapping the layer key once, hitting a symbol then carrying on. It
was a conscious decision to favour tapping, for example, layer, equals, layer,
right angled bracket, space, layer, dollar then typing a variable name over
mixing in a variety of tapping and holding modifiers.

Layers two and three remain are not one-shot so that numerals, navigation,
brightness controls and so on can be entered and modified consistently. A press
of the return to base layer thumb key is required to get back to the base layer.

## Base layer

![Base Layer](https://i.imgur.com/k3AQIGt.png)

The base layer uses Colemak DH 2020 with shift on the outside left thumb key,
space on the inside left thumb key, enter on the inside right thumb key and
layer one on the outside right thumb key. Backspace is available on top right
key.

Homerow modifiers are available on the following keys:

* Hold A or O for Shift
* Hold R or I for Control
* Hold S or E for Alt
* Hold T or N for GUI / Windows

Note that this layout is mirrored in layer two so that the modifiers are
available for numerals and navigation.

## Layer one: symbols

![Layer 1](https://i.imgur.com/hd9YTNV.png)

Layer one is influenced by the layout of symbols on UK ISO keyboards. Escape and
Tab appear on the left hand side and the symbols that appear above 2 to 8 appear
across the top row. Underscore / minus and plus / equals appear at the right
hand side as pairs of separate keys situated above and below each other.

In the middle there are similar pairs of keys that are usually found to the
right of the middle row: tilde / hash, at / quote and colon / semicolon. On the
bottom right there is the exclamation mark that would have appeared above the
number one position if there was space, but which is now placed on the same key
as the shifted question mark in the base layer. The right angled bracket is also
available because it may feel more natural to type => as a double L1 tap. The
pipe / backslash key pair appears on the far left and taking up the rest of the
left side there are pairs of braces and brackets.

Shift and enter remain available on the inside left and right thumb keys. The
outside left thumb key returns to base layer. The outside right thumb key goes
to layer two and the bottom left key goes to layer three. These are not one shot
keys so the keyboard will remain in layer two or three until the return to base
layer key is pressed.

## Layer two: numerals and navigation

![Layer 2](https://i.imgur.com/m0teEmJ.png)

TBA

## Layer three: function keys

![Layer 3](https://i.imgur.com/VMxukue.png)

TBA

## Where is the keymap.c?

The keymap.c file is not published to the repository. It is generated from
`keymap.json` by the build system.

This avoids duplicating information and allow users to edit their keymap from
the qmk configurator web interface.

## How do I edit and update the keymap?

The `keymap.json` file is generated from the qmk configurator interface and
formatted for better readability in the context of the Ferris keyboard.

To edit it, you may:

* Edit it directly from a text editor.
* Edit it from the qmk configurator.

If you decide to use the latter workflow, here are the steps to follow:

* From the qmk configurator, hit the "import QMK keymap json file" button (it
  has a drawing with an up arrow on it).
* Browse to the location of your keymap (for example, `<your qmk
  repo>/keyboards/ferris/keymaps/default/keymap.json`)
* Perform any modification to the keymap in the web UI
* Export the keymap to your downloads folder, by hitting the "Export QMK keymap
  json file" button (it has a drawing with a down arrow on it)
* Override your original keymap with the output of formatting the exported
  keymap by running a command such as this one from the root of your qmk repo:

```shell
 ./keyboards/handwired/ferris/keymaps/json2crab.py --input <Your download
directory>/default.json >
./keyboards/handwired/ferris/keymaps/default/keymap.json```

Note that you may first need to make json2crab executable by using `chmod +x` on
it. Also note that you may then want to remove the exported keymap from your
dowload directory.
