# Hannah's Ferris Sweep Layout

This is my first attempt at a layout for my new Ferris Sweep. I am attempting to
integrate Colemak DH, which is new to me, and keep everything else as familiar
as possible, so I have tried to take my cues for numbers and symbols from the UK
ISO keyboard layout that I know.

Broadly speaking, this is designed to be a one-shot layout. The base layer has a
one-shot shift key on the left thumb and one-shot layer change to layer one on
the right thumb so most of the time will be spent in the base layer and, aside
from the homerow modifiers, there is no chording or comboing.

In practice, a single tap of the layer key gets to the Symbols layer and a
double tap of the layer key gets to the Numbers and Navigation layer. Most of
the time you will be tapping the layer key once, hitting a symbol then carrying
on. This was a conscious decision to favour tapping over holding down shift, or
having to retain knowledge of which layer the keyboard is in.

The Numbers and Navigation layer is not one-shot to allow for the extended entry
of numbers and extended navigation. The Utility layer is intended as a one-shot
shortcut to various symbol keys for performing calculations with numbers while
in the Numbers and Navigation layer.

## Base Layer

![Base Layer](https://i.imgur.com/NUZzOuL.png)

The base layer uses Colemak DH 2020 with shift on the outside left thumb key,
space on the inside left thumb key, enter on the inside right thumb key and
layer one on the outside right thumb key. Backspace is available on top right
key.

Homerow modifiers are available on the following keys:

* Hold A or O for Shift
* Hold R or I for Control
* Hold S or E for Alt
* Hold T or N for GUI / Windows

Note that this layout of modifiers is mirrored in layer two.

## Layer One: Symbols

![Layer 1](https://i.imgur.com/zYAz1a4.png)

Layer one is influenced by the layout of symbols on UK ISO keyboards. Escape and
Tab appear on the left hand side and the symbols that appear above 2 to 8 appear
across the top row. Underscore / minus and plus / equals appear at the right
hand side as pairs of separate keys situated above and below each other.

In the middle there are similar pairs of keys that are usually found to the
right of the middle row: tilde / hash, at / quote and colon / semicolon. On the
bottom right there is the exclamation mark that would have appeared above the
number one position if there was space, but which is now placed on the same key
as the shifted question mark in the base layer. The grave appears at the bottom
right as a compromise because there is no room on the top left of any layer for
it. The pipe / backslash key pair appears on the far left and taking up the rest
of the left side there are pairs of braces and brackets.

Shift and enter keys remain available on the inside left and right thumb keys.
The outside left thumb key returns to base layer. The outside right thumb key
goes to layer two and the bottom left key goes to layer three.

## Layer Two: Numbers and Navigation

![Layer 2](https://i.imgur.com/ytmFjSk.png)

Numbers appear along the top row as they do on standard keyboards. On the right
side the navigation keys are arranged on the traditional Vim navigation keys
(hjkl in QWERTY keyboards) with the home, page down, page up and end keys below
them. The delete and insert keys appear on the far right.

On the left there is a caps lock key and the bottom left key goes to layer
three. Media keys take up most of the rest of the left hand side. The final keys
on the inside of the left side are Vim shortcuts: capital-V to enter visual mode
and colon to enter cmdline mode.

## Layer three: Utility

![Layer 3](https://i.imgur.com/5irKSZc.png)

This layer is still a work in progress. At the moment it contains a mirror of
various symbols required for calculations that can be accessed from the Numbers
and Navigation layer quickly. The left hand side has all twelve function keys.

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
./keyboards/handwired/ferris/keymaps/default/keymap.json
```

Note that you may first need to make json2crab executable by using `chmod +x` on
it. Also note that you may then want to remove the exported keymap from your
dowload directory.
