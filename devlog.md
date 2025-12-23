# 23/12/2025 00:59
Hi! Documenting my thought process and some recurring bugs. So, for starters let's define the MVP:

## The program must be able to read `.cldr` files
`.cldr` files will be plain formatted text to store the user's events they want to save.
This file must be selected by the env variable `$CALENDAR_FILE` by default it's value is `~/calendar.cldr`, if it not exists, it creates it.

Structure to store an event should be as follows:
`<year> <month> <day> [tags] <event>`

Comments should be made by using `#`

## The program must be able to query events in the `.cldr` file
At the beggining it should be enough with querying events `before`, `now` and `after`. The events are measured in *days*

I will try to implement all of this today

---

