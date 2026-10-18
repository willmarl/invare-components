---
name: new-unit
description: >-
  Research a newly added electronics catalog unit, fill desc.md and info.json,
  check unit photos for PII metadata with exiftool, and add a compile-checked
  Arduino sketch when the part is MCU-applicable. Use when the user adds a
  unit under units/, asks to fill desc.md or info.json, or invokes the
  new-unit skill.
disable-model-invocation: true
---

# New catalog unit

Fill one or more `units/<slug>/` folders. Do not commit or push unless the user asks.

## Find the units

Treat as new when any of these is true:

- The user names the folder.
- `git status` shows it untracked or the `desc.md` is empty.
- `info.json` has an empty `exampleIdeas` or `tags` array.

Ignore folders whose name contains ` copy`. Skip a folder with no photo and no `info.json`.

Leave a `desc.md` alone when it already has prose and does not end with `> AI created desc`. Those notes are handwritten. Leave an existing `code/arduino.ino` alone unless it fails to compile or the user asks to replace it.

## Photo metadata

Run exiftool on every image in the unit folder (`jpg`, `jpeg`, `png`, `webp`, `heic`). A clean photo has none of these tags set:

```bash
exiftool -a -G1 -s -ee -gps:all \
  -Artist -Copyright -ImageDescription -OwnerName -CameraOwnerName \
  -BodySerialNumber -LensSerialNumber -InternalSerialNumber -ImageUniqueID \
  -UserComment -XPAuthor -XPComment -XPKeywords \
  -Creator -By-line -Credit -Caption-Abstract \
  units/<slug>/*.<ext>
```

Width, height, encoding, and resolution are fine. Treat a hit as PII: GPS, a person's name, a copyright or credit string, a camera or lens serial, an image unique ID, a comment, or a path that contains a username. Report the file and tag names. Do not strip tags unless the user asks, and do not treat that unit as ready to commit.

## Research

Read the photo and `info.json`. Silkscreen and chip markings win over a guessed `model`; say so in the note if you change it. Look up the datasheet. Use practical hobby-module numbers and say when clones vary. Skip the write-up for parts with nothing to look up: cables, battery holders, cells, capacitors, resistors, terminals, heatsinks, thermal pads, barrel jacks, dip/slide/e-switches.

## desc.md

Match nearby unit notes: one short paragraph (what it is, the caveat that actually bites), then bullets, then the marker. Keep the marker so AI notes stay distinct from handwritten ones.

```markdown
One or two sentences. Voltage, current, or setup caveat in the same breath.

- Operating Voltage : 3.3V – 5V
- Current : ~1A without heatsink

> AI created desc
```

Use `Label : value`. An en dash for ranges. Only include specs that matter (voltage, current, range, resolution, protocol, pin or magnet caveat).

## info.json

Required keys: `name`, `model`, `exampleIdeas` (2–4 short uses), `tags` (lowercase, 3–6). Keep a `name` or `model` the user already set unless the photo shows a different part.

## Arduino sketch

Write `code/arduino.ino` only when an Arduino can read or drive the part (GPIO, ADC, I2C, SPI, UART, or a shield pinout).

Skip, and do not invent a sketch, for:

- The trivial parts listed above
- The MCU board itself
- A consumable that a sibling already drives (RFID card or tag vs the RC522 unit, IR remote vs the IR receiver)

Before writing, search Library Manager:

```bash
arduino-cli lib search <chip or part>
```

If a library exists, use it and put this on line 1, with the author from the search result (names collide):

```cpp
// use `Library Name` lib by author
```

Use the library's real include and API. Read the installed header; do not guess method names. Prefer the same library a sibling unit already uses (step/dir drivers use AccelStepper by Mike McCauley). If two installed libraries provide the same header, uninstall the one the sketch does not include.

Sketch shape: `#define` pins, `Serial.begin(9600)`, a short loop that shows the part works. Comment the one electrical gotcha (enable polarity, Vref, 3.3V-only, magnet). No long tutorials.

Default board is Arduino Nano, FQBN `arduino:avr:nano`. Use `arduino:avr:uno` for an Uno shield and `arduino:avr:mega` when the library or pin count needs it. Compile the board the sketch is for. Compile only. Do not upload.

`arduino-cli` requires the folder name to match the `.ino`. Compile from a temp copy:

```bash
slug=<unit-folder>
dir=/tmp/arduino-verify-$slug
rm -rf "$dir" && mkdir -p "$dir/arduino"
cp "units/$slug/code/arduino.ino" "$dir/arduino/arduino.ino"
arduino-cli compile --fqbn arduino:avr:nano "$dir/arduino"
```

If the core is missing a library the sketch includes (`Servo`, `Ethernet`, `SD`), install it from Library Manager and compile again. Fix compile errors before finishing. A passing compile does not prove the pin map or voltage; keep those caveats in `desc.md`.

## Done

Tell the user which units were filled, which got a sketch, the FQBN that compiled, whether each photo was free of PII metadata, and which units were skipped and why.

See [examples.md](examples.md) for a filled note and sketch.
