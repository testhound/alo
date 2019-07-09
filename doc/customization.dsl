<!DOCTYPE style-sheet PUBLIC "-//James Clark//DTD DSSSL Style Sheet//EN" [
<!ENTITY dbstyle PUBLIC "-//Norman Walsh//DOCUMENT DocBook Print Stylesheet//EN" CDATA DSSSL>
]>

<style-sheet>
<style-specification use="docbook">
<style-specification-body>

<!-- See  /usr/share/sgml/docbook/dsssl-stylesheets/print/dbparam.dsl for
     available parameters.  Copy them here and change the values as
     desired. -->

(define %generate-article-toc% 
  ;; REFENTRY generate-article-toc
  ;; PURP Should a Table of Contents be produced for Articles?
  ;; DESC
  ;; If true, a Table of Contents will be generated for each 'Article'.
  ;; /DESC
  ;; AUTHOR N/A
  ;; /REFENTRY
  #t)

(define %generate-article-titlepage% 
  ;; REFENTRY generate-article-titlepage
  ;; PURP Should an article title page be produced?
  ;; DESC
  ;; If true, a title page will be generated for each 'Article'.
  ;; /DESC
  ;; AUTHOR N/A
  ;; /REFENTRY
  #t)

(define %generate-article-titlepage-on-separate-page%
  ;; REFENTRY generate-article-ttlpg-on-sep-page
  ;; PURP Should the article title page be on a separate page?
  ;; DESC
  ;; If true, the title page for each 'Article' will occur on its own page.
  ;; /DESC
  ;; AUTHOR N/A
  ;; /REFENTRY
  #t)


(define %generate-article-toc-on-titlepage%
  ;; REFENTRY generate-article-toc-on-titlepage
  ;; PURP Should the Article TOC appear on the Article title page?
  ;; DESC
  ;; If true, the Article TOC will be placed on the Article title page.
  ;; If false,
  ;; the TOC will be placed on separate page(s) after the title page.
  ;; If false, %generate-article-titlepage-on-separate-page% should be
  ;; true.
  ;; /DESC
  ;; AUTHOR N/A
  ;; /REFENTRY
  #f)

(define %section-autolabel%
  ;; REFENTRY section-autolabel
  ;; PURP Are sections enumerated?
  ;; DESC
  ;; If true, unlabeled sections will be enumerated.
  ;; /DESC
  ;; AUTHOR N/A
  ;; /REFENTRY
  #t)


(define %two-side% 
  ;; REFENTRY two-side
  ;; PURP Is two-sided output being produced?
  ;; DESC
  ;; If '%two-side%' is true, headers and footers are alternated
  ;; so that the "outer" and "inner" headers will be correctly
  ;; placed in the bound document.
  ;; /DESC
  ;; AUTHOR N/A
  ;; /REFENTRY
  #t)




<!-- Customized from dbautoc.dsl.  Set the depth to which section numbers are
     reported in the TOC.  Learned from,
       http://lists.oasis-open.org/archives/docbook/199910/msg00088.html  -->
(define (toc-depth nd)
  (if (string=? (gi nd) (normalize "book"))
      7
      (if (string=? (gi nd) (normalize "article"))
	  ;; Article toc depth:
          2
          1)))

<!-- Customized from dbttlpg.dsl.  Define the elements which should appear
     on the cover page (recto = righthand) for an article.  Most notably,
     include "graphic" -->
(define (article-titlepage-recto-elements)
  (list (normalize "title") 
	(normalize "subtitle") 
	(normalize "corpauthor") 
	(normalize "authorgroup") 
	(normalize "author") 
	(normalize "graphic") 
	(normalize "abstract")
	(normalize "copyright")))

<!-- Also from dbttlpg.dsl.  Override "(element graphic...)"  within the
     article-titlepage-recto-mode mode.  Mainly to add "scale" which was
     not present in the default style.  -->
(mode article-titlepage-recto-mode
  (element graphic
    (let* ((nd (current-node))
	   (fileref (attribute-string "fileref" nd))
	   (entityref (attribute-string "entityref" nd))
	   (format (attribute-string "format" nd))
	   (scale (attribute-string "scale" nd))
	   (align (attribute-string "align" nd)))
      (if (or fileref entityref) 
	  (make external-graphic
	    notation-system-id: (if format format "")
	    entity-system-id: (if fileref 
				  (graphic-file fileref)
				  (if entityref 
				      (entity-generated-system-id entityref)
				      ""))
	    display?: #t
	    scale: (if scale (/ (string->number scale) 100) 1)
	    display-alignment: 'center)
	  (empty-sosofo))))
)



</style-specification-body>
</style-specification>
<external-specification id="docbook" document="dbstyle">
</style-sheet>

