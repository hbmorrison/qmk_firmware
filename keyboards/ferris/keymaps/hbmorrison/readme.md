# Hannah's Ferris Sweep Layout

This is my first attempt at a layout for my new Ferris Scoop. I am attempting to
integrate Colemak DH, which is new to me, and keep everything else as familiar
as possible, so I have tried to take my cues for numbers and symbols from the UK
ISO keyboard layout that I know.

Broadly speaking, this is designed to be a one-shot layout. The base layer has a
one-shot shift key on the left thumb and one-shot layer change to layer one on
the right thumb so most of the time will be spent in the base layer and, aside
from the homerow modifiers, there will be no chording or comboing.

Layers two and three are sticky and require a thumb keypress to return to the
base layer so that numerals, navigation, brightness controls and so on can be
entered consistently.

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

![Layer 1](https://i.imgur.com/fm7dvZp.png)

Layer one is influenced by the layout of symbols on UK ISO keyboards. Escape and
Tab appear on the left hand side and the symbols that appear above 2 to 8 appear
across the top row. Underscore / minus and plus / equals appear at the right
hand side as separate keys.

In the middle there are similar pairs of keys that are usually found to the
right of the middle row: tilde / hash, at / quote, colon / semicolon. The pipe /
backslash pair also appears here even though it is usually found at the bottom
left, so that all of the pairs of keys are located in the same cluster. On the
left side there are pairs of braces and brackets. Finally on the bottom right
there is the missing exclamation mark, which is placed on the same key as the
shifted question mark in the base layer. The right angled bracket also appears
even though it is available shifted in the base layer, because it may feel more
natural to type => as a double L1 tap.

Shift and enter remain available on the inside left and right thumb keys. These
remain throughout the layers for consistency. The outside left thumb key returns
to base layer. Outside of the base layer the outside left always returns to the
base layer so an easy way to fail safe back to the base layer from anywhere is
to tap the outside right then outside left thumb keys.

The outside right thumb key goes to layer two and the bottom left key goes to
layer three. These are not one shot keys so the keyboard will remain in layer
two and three until the return to layer one key is pressed.

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
