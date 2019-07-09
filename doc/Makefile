# Note, this requires "docbook2pdf" and a number of dependent
# packages.   It should work on Red Hat 7.x where x >= 2, assuming
# the required packages are installed.

default: new_macro.pdf new_macro.rtf

# Simple pattern rule.  For a given file foo.xml, invoke as follows,
# $ make foo.pdf

%.pdf : %.xml %.dsl Makefile
	docbook2pdf -d %.dsl $<


new_macro.pdf : new_macro.xml new_macro.dsl Makefile
	docbook2pdf -d new_macro.dsl new_macro.xml

new_macro.rtf : new_macro.xml new_macro.dsl_MSWORD Makefile
	docbook2rtf -d new_macro.dsl_MSWORD new_macro.xml
