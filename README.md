# organized — Hardware Inventory Shell
 
An interactive shell to manage a doubly linked list of hardware components. Supports adding, deleting, sorting, and displaying nodes.
 
## Usage
 
```sh
./organized
```
 
## Commands
 
| Command | Description |
|---------|-------------|
| `add TYPE NAME [TYPE NAME ...]` | Add one or more components |
| `del ID [ID ...]` | Delete components by ID |
| `sort TYPE\|NAME\|ID [-r] [...]` | Sort by up to 3 criteria (optionally reversed) |
| `disp` | Display all components |
 
Valid types: `ACTUATOR`, `DEVICE`, `PROCESSOR`, `SENSOR`, `WIRE`.
 
## Build
 
```sh
make
```
 
## Author
 
EPITECH PROJECT, 2025 — organized