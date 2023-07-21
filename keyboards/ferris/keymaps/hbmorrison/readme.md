# Hannah's Ferris Sweep Layout

This is my first attempt at a layout for my new Ferris Sweep. I am attempting to
integrate Colemak DH, which is new to me, and keep everything else as familiar
as possible, so I have tried to take my cues for numbers and symbols from the UK
ISO keyboard layout that I know.

Broadly speaking, this is designed to a layout where keys and modifiers are
tapped rather than held down. Aside from homerow modifiers, there is no chording
or comboing. In practice, a single tap of the layer key gets to the symbols
layer and a double tap of the layer key gets to the numbers and navigation
layer. Most of the time you will be tapping the layer key once, hitting a symbol
then carrying on in the base layer.

The numbers and navigation layer is sticky to allow for the extended entry of
numbers and extended navigation. The Utility layer is intended as a shortcut to
various symbol keys for performing calculations with numbers while in the
numbers and navigation layer.

## Base Layer

![Base Layer](https://i.imgur.com/NUZzOuL.png)

The base layer uses Colemak DH 2020 with `shift` on the outside left thumb key,
`space` on the inside left thumb key, `enter` on the inside right thumb key and
`L1` (layer one) on the outside right thumb key. The `backspace` key is
available at the top right. When tapped, `shift` key that will capitalise or
shift the next key that is tapped. It does nothing when held down. Similarly,
the `L1` key will switch to the symbols layer and return to the base layer
immediately after a single symbol key has been tapped.

Homerow modifiers are available on the following keys:

* Hold `A` or `O` for `shift`
* Hold `R` or `I` for `control`
* Hold `S` or `E` for `alt`
* Hold `T` or `N` for `win` / `cmd`

Note that this layout of homerow modifiers is mirrored in layer two.

## Layer One: Symbols

![Symbols Layer](https://i.imgur.com/zYAz1a4.png)

Layer one is influenced by the layout of symbols on UK ISO keyboards. The
`escape` and `tab` keys are on the left hand side and the symbols usually found
above `2` to `8` are on the top row. The `minus` / `underscore` and `equals` /
`plus` are on the right hand side as pairs of separate keys situated above and
below each other.

In the middle there are similar pairs of keys that are usually found to the
right of the middle row: `hash` / `tilde` , `quote` / `at`  and `semicolon` /
`colon`. On the bottom right there is the `exclamation mark` key that would have
appeared above the number one position if there was space, but which is now
placed on the same key as the `slash` / `question mark` in the base layer. The
`grave` key is on the bottom right as a compromise because there is no room on
the top left of any layer for it. The `backslash` / `pipe` key pair is on the
far left and taking up the rest of the left side there are pairs of braces and
brackets.

The `shift` and `enter` keys remain on the inside left and right thumb keys. The
outside left thumb key, `L0`, returns to the base layer. `L2` on the outside
right thumb key goes to the numbers and navigation layer and `L3` at the bottom
left goes to the utility layer.

## Layer Two: Numbers and Navigation

![Numbers and Navigation Layer](https://i.imgur.com/ytmFjSk.png)

Numbers appear along the top row as they do on standard keyboards. On the right
side the navigation keys are arranged on the traditional Vim navigation keys
(`hjkl` in QWERTY keyboards) with the `home`, `page down`, `page up` and `end`
keys below them. The `delete` and `insert` keys are on the far right.

On the left there is a `caps lock` key and `L3` at the bottom left goes to the
utility layer. Media keys take up most of the rest of the left hand side. The
final keys on the inside of the left side are Vim shortcuts: `capital-v` to
enter visual mode and `colon` to enter cmdline mode.

The thumb keys remain consistent on all layers: `shift` and `enter` on the
inside keys and `L0` on the outside left thumb key.

## Layer three: Utility

![Utility Layer](https://i.imgur.com/5irKSZc.png)

This layer is still a work in progress. At the moment it contains a mirror of
various symbols required for calculations that can be accessed from the numbers
and navigation layer quickly. The left hand side has all twelve function keys.

Again the thumb keys remain consistent on all layers: `shift` and `enter` on the
inside keys and `L0` on the outside left thumb key.

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
./keyboards/handwired/ferris/keymaps/json2crab.py --input <Your download directory>/default.json > ./keyboards/handwired/ferris/keymaps/default/keymap.json
```

Note that you may first need to make json2crab executable by using `chmod +x` on
it. Also note that you may then want to remove the exported keymap from your
dowload directory.
