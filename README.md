# invare-components

Public component library for **Invare**, a private hardware inventory / wiki site.

This repo is the source of truth for official parts shown on the site’s wiki. The website pulls every folder under `units/` and syncs them as official units (name, description, tags, photos, example code).

---

## Layout

```
invare-components/
├── units/                 # one folder per official unit (folder name = slug)
│   └── micro-servo/
│       ├── info.json      # required — name, tags, etc.
│       ├── desc.md        # required — description shown on wiki
│       ├── *.jpg|png|…    # optional — first image becomes the unit photo
│       └── code/          # optional — example sketches
│           ├── arduino.ino
│           ├── esp32.ino
│           ├── micropython.py
│           └── python.py
└── templates/foo/         # copy this when adding a new unit
```

The **folder name is the official slug** (and wiki URL path). Keep names kebab-case — e.g. `pi-4` → `/wiki/pi-4`.

> This repo is only for hardware units. Concept / tutorial wiki pages are managed separately on the site.

---

## Unit files

### `info.json` (required)

```json
{
  "name": "Micro Servo",
  "model": "MG90S",
  "exampleIdeas": ["Robot arm joint", "Pan/tilt camera mount"],
  "tags": ["servo", "motor", "pwm", "robotics", "output"]
}
```

| Field          | Required | Notes                         |
| -------------- | -------- | ----------------------------- |
| `name`         | yes      | Display name on the wiki      |
| `model`        | no       | Specific part / board model   |
| `exampleIdeas` | no       | Short project ideas           |
| `tags`         | no       | Lowercase; used for filtering |
| `description`  | no\*     | Prefer `desc.md` instead      |

\*Description is required somehow: either `desc.md` or a `description` string in `info.json`.

### `desc.md` (required in practice)

Plain markdown (or plain text) overview shown on the unit page.

### Images (optional)

Any `jpg`, `jpeg`, `png`, `webp`, `gif`, etc. in the unit folder. Sync picks up images from the folder root.

> Reminder to remove metadata of image

### `code/` (optional)

One file per language/platform. Filenames are stored as-is and shown in the unit’s code viewer (e.g. `arduino.ino`, `esp32.ino`, `micropython.py`, `python.py`).

---

## Adding a unit

1. Copy the template:

   ```bash
   cp -r templates/foo units/my-new-part
   ```

2. Fill in `info.json` and `desc.md`, drop a photo, and add example code under `code/` if you have it.

3. Commit and push to `main`.

4. On the Invare site, sync official units from this repo (`OFFICIAL_UNITS_REPO=willmarl/invare-components`), then add the slug to the wiki category config so it shows up in the homepage grouping.
