let SessionLoad = 1
if &cp | set nocp | endif
let s:cpo_save=&cpo
set cpo&vim
inoremap <expr> <Down> pumvisible() ? "\" : "\<Down>"
inoremap <expr> <Up> pumvisible() ? "\" : "\<Up>"
imap <Nul> <C-Space>
inoremap <C-Space> 
imap <S-Tab> <Plug>SuperTabBackward
inoremap <C-Tab> 	
snoremap <silent>  c
nnoremap <silent>  :TmuxNavigateLeft
xnoremap <silent> 	 :call UltiSnips#SaveLastVisualSelection()gvs
snoremap <silent> 	 :call UltiSnips#ExpandSnippet()
nnoremap <silent> <NL> :TmuxNavigateDown
nnoremap <silent>  :TmuxNavigateUp
snoremap <silent>  :call UltiSnips#ListSnippets()
nnoremap <silent>  :TmuxNavigateRight
xnoremap <silent>  :call multiple_cursors#new("v", 0)
nnoremap <silent>  :call multiple_cursors#new("n", 1)
map  <Plug>(ctrlp)
snoremap  "_c
nnoremap <silent>  :TmuxNavigatePrevious
nnoremap <silent> '[ :call signature#mark#Goto("prev", "line", "alpha")
nnoremap <silent> '] :call signature#mark#Goto("next", "line", "alpha")
nmap <silent> ,w,y <Plug>VimwikiMakeYesterdayDiaryNote
nmap <silent> ,w,t <Plug>VimwikiTabMakeDiaryNote
nmap <silent> ,w,w <Plug>VimwikiMakeDiaryNote
nmap <silent> ,w,i <Plug>VimwikiDiaryGenerateLinks
nmap <silent> ,wi <Plug>VimwikiDiaryIndex
nmap <silent> ,ws <Plug>VimwikiUISelect
nmap <silent> ,wt <Plug>VimwikiTabIndex
nmap <silent> ,ww <Plug>VimwikiIndex
map ,wc :call VimuxRunCommand("cd ~/git/notes; nohup ./save_and_update.sh & exit")
map ,l :VimuxCloseRunner
map ,u :UltiSnipsEdit
nmap ,wah :VimwikiAll2HTML
nmap ,dsc :delmarks s l e :normal F\mlf{lmsh%me`sd`lms`ex`s:delmarks s l e
nnoremap ,jd :YcmCompleter GoTo
nnoremap <silent> ,w :ArgWrap
nnoremap ,n :NERDTreeToggle
nmap ,t :tabedit:NERDTreeToggle
map ,s :tabnew:Startify      " run startify 
map ,fal :s//&/g<Left><Left>
map ,fa :%s//&/g<Left><Left>
map ,frl :s///g<Left><Left>
map ,fr :%s///g<Left><Left>
map ,m :w|silent make|redraw!|cc
nmap ,d "_d
nmap ,g :normal mggg=G'g:delmarks gzz
nnoremap ,a :call AutoHighlightToggle()
map ,; :ts       " show list of files in which the tag is found
map ,/ :pop      " go back one tag
map ,.        " dive into the tag
nnoremap ,c :call ToggleCursorLines()
nnoremap ,p :call TogglePaste()
nnoremap ,r :call NumberToggle()
nnoremap , <Nop>
vnoremap . :normal @a
vnoremap // y/"
xnoremap <silent> <expr> A targets#e('A')
onoremap <silent> AL$ :call targets#o('$LA', v:count1)
onoremap <silent> AN$ :call targets#o('$NA', v:count1)
onoremap <silent> Al$ :call targets#o('$lA', v:count1)
onoremap <silent> An$ :call targets#o('$nA', v:count1)
onoremap <silent> A$ :call targets#o('$cA', v:count1)
onoremap <silent> AL& :call targets#o('&LA', v:count1)
onoremap <silent> AN& :call targets#o('&NA', v:count1)
onoremap <silent> Al& :call targets#o('&lA', v:count1)
onoremap <silent> An& :call targets#o('&nA', v:count1)
onoremap <silent> A& :call targets#o('&cA', v:count1)
onoremap <silent> AL| :call targets#o('|LA', v:count1)
onoremap <silent> AN| :call targets#o('|NA', v:count1)
onoremap <silent> Al| :call targets#o('|lA', v:count1)
onoremap <silent> An| :call targets#o('|nA', v:count1)
onoremap <silent> A| :call targets#o('|cA', v:count1)
onoremap <silent> AL\ :call targets#o('\LA', v:count1)
onoremap <silent> AN\ :call targets#o('\NA', v:count1)
onoremap <silent> Al\ :call targets#o('\lA', v:count1)
onoremap <silent> An\ :call targets#o('\nA', v:count1)
onoremap <silent> A\ :call targets#o('\cA', v:count1)
onoremap <silent> AL/ :call targets#o('/LA', v:count1)
onoremap <silent> AN/ :call targets#o('/NA', v:count1)
onoremap <silent> Al/ :call targets#o('/lA', v:count1)
onoremap <silent> An/ :call targets#o('/nA', v:count1)
onoremap <silent> A/ :call targets#o('/cA', v:count1)
onoremap <silent> AL# :call targets#o('#LA', v:count1)
onoremap <silent> AN# :call targets#o('#NA', v:count1)
onoremap <silent> Al# :call targets#o('#lA', v:count1)
onoremap <silent> An# :call targets#o('#nA', v:count1)
onoremap <silent> A# :call targets#o('#cA', v:count1)
onoremap <silent> AL* :call targets#o('*LA', v:count1)
onoremap <silent> AN* :call targets#o('*NA', v:count1)
onoremap <silent> Al* :call targets#o('*lA', v:count1)
onoremap <silent> An* :call targets#o('*nA', v:count1)
onoremap <silent> A* :call targets#o('*cA', v:count1)
onoremap <silent> AL_ :call targets#o('_LA', v:count1)
onoremap <silent> AN_ :call targets#o('_NA', v:count1)
onoremap <silent> Al_ :call targets#o('_lA', v:count1)
onoremap <silent> An_ :call targets#o('_nA', v:count1)
onoremap <silent> A_ :call targets#o('_cA', v:count1)
onoremap <silent> AL~ :call targets#o('~LA', v:count1)
onoremap <silent> AN~ :call targets#o('~NA', v:count1)
onoremap <silent> Al~ :call targets#o('~lA', v:count1)
onoremap <silent> An~ :call targets#o('~nA', v:count1)
onoremap <silent> A~ :call targets#o('~cA', v:count1)
onoremap <silent> AL= :call targets#o('=LA', v:count1)
onoremap <silent> AN= :call targets#o('=NA', v:count1)
onoremap <silent> Al= :call targets#o('=lA', v:count1)
onoremap <silent> An= :call targets#o('=nA', v:count1)
onoremap <silent> A= :call targets#o('=cA', v:count1)
onoremap <silent> AL- :call targets#o('-LA', v:count1)
onoremap <silent> AN- :call targets#o('-NA', v:count1)
onoremap <silent> Al- :call targets#o('-lA', v:count1)
onoremap <silent> An- :call targets#o('-nA', v:count1)
onoremap <silent> A- :call targets#o('-cA', v:count1)
onoremap <silent> AL+ :call targets#o('+LA', v:count1)
onoremap <silent> AN+ :call targets#o('+NA', v:count1)
onoremap <silent> Al+ :call targets#o('+lA', v:count1)
onoremap <silent> An+ :call targets#o('+nA', v:count1)
onoremap <silent> A+ :call targets#o('+cA', v:count1)
onoremap <silent> AL: :call targets#o(':LA', v:count1)
onoremap <silent> AN: :call targets#o(':NA', v:count1)
onoremap <silent> Al: :call targets#o(':lA', v:count1)
onoremap <silent> An: :call targets#o(':nA', v:count1)
onoremap <silent> A: :call targets#o(':cA', v:count1)
onoremap <silent> AL; :call targets#o(';LA', v:count1)
onoremap <silent> AN; :call targets#o(';NA', v:count1)
onoremap <silent> Al; :call targets#o(';lA', v:count1)
onoremap <silent> An; :call targets#o(';nA', v:count1)
onoremap <silent> A; :call targets#o(';cA', v:count1)
onoremap <silent> AL. :call targets#o('.LA', v:count1)
onoremap <silent> AN. :call targets#o('.NA', v:count1)
onoremap <silent> Al. :call targets#o('.lA', v:count1)
onoremap <silent> An. :call targets#o('.nA', v:count1)
onoremap <silent> A. :call targets#o('.cA', v:count1)
onoremap <silent> AL, :call targets#o(',LA', v:count1)
onoremap <silent> AN, :call targets#o(',NA', v:count1)
onoremap <silent> Al, :call targets#o(',lA', v:count1)
onoremap <silent> An, :call targets#o(',nA', v:count1)
onoremap <silent> A, :call targets#o(',cA', v:count1)
onoremap <silent> Al` :call targets#o('`lA', v:count1)
onoremap <silent> An` :call targets#o('`nA', v:count1)
onoremap <silent> A` :call targets#o('`cA', v:count1)
onoremap <silent> Al' :call targets#o('''lA', v:count1)
onoremap <silent> An' :call targets#o('''nA', v:count1)
onoremap <silent> A' :call targets#o('''cA', v:count1)
onoremap <silent> Al" :call targets#o('"lA', v:count1)
onoremap <silent> An" :call targets#o('"nA', v:count1)
onoremap <silent> A" :call targets#o('"cA', v:count1)
onoremap <silent> Al> :call targets#o('>lA', v:count1)
onoremap <silent> An> :call targets#o('>nA', v:count1)
onoremap <silent> A> :call targets#o('>cA', v:count1)
onoremap <silent> Al< :call targets#o('<lA', v:count1)
onoremap <silent> An< :call targets#o('<nA', v:count1)
onoremap <silent> A< :call targets#o('<cA', v:count1)
onoremap <silent> Al] :call targets#o(']lA', v:count1)
onoremap <silent> An] :call targets#o(']nA', v:count1)
onoremap <silent> A] :call targets#o(']cA', v:count1)
onoremap <silent> Al[ :call targets#o('[lA', v:count1)
onoremap <silent> An[ :call targets#o('[nA', v:count1)
onoremap <silent> A[ :call targets#o('[cA', v:count1)
onoremap <silent> AlB :call targets#o('BlA', v:count1)
onoremap <silent> AnB :call targets#o('BnA', v:count1)
onoremap <silent> AB :call targets#o('BcA', v:count1)
onoremap <silent> Al} :call targets#o('}lA', v:count1)
onoremap <silent> An} :call targets#o('}nA', v:count1)
onoremap <silent> A} :call targets#o('}cA', v:count1)
onoremap <silent> Al{ :call targets#o('{lA', v:count1)
onoremap <silent> An{ :call targets#o('{nA', v:count1)
onoremap <silent> A{ :call targets#o('{cA', v:count1)
onoremap <silent> Alb :call targets#o('blA', v:count1)
onoremap <silent> Anb :call targets#o('bnA', v:count1)
onoremap <silent> Ab :call targets#o('bcA', v:count1)
onoremap <silent> Al) :call targets#o(')lA', v:count1)
onoremap <silent> An) :call targets#o(')nA', v:count1)
onoremap <silent> A) :call targets#o(')cA', v:count1)
onoremap <silent> Al( :call targets#o('(lA', v:count1)
onoremap <silent> An( :call targets#o('(nA', v:count1)
onoremap <silent> A( :call targets#o('(cA', v:count1)
onoremap <silent> Ala :call targets#o('alA', v:count1)
onoremap <silent> Ana :call targets#o('anA', v:count1)
onoremap <silent> Aa :call targets#o('acA', v:count1)
onoremap <silent> Alt :call targets#o('tlA', v:count1)
onoremap <silent> Ant :call targets#o('tnA', v:count1)
onoremap <silent> At :call targets#o('tcA', v:count1)
vmap H ^
nmap H ^
xnoremap <silent> <expr> I targets#e('I')
onoremap <silent> IL$ :call targets#o('$LI', v:count1)
onoremap <silent> IN$ :call targets#o('$NI', v:count1)
onoremap <silent> Il$ :call targets#o('$lI', v:count1)
onoremap <silent> In$ :call targets#o('$nI', v:count1)
onoremap <silent> I$ :call targets#o('$cI', v:count1)
onoremap <silent> IL& :call targets#o('&LI', v:count1)
onoremap <silent> IN& :call targets#o('&NI', v:count1)
onoremap <silent> Il& :call targets#o('&lI', v:count1)
onoremap <silent> In& :call targets#o('&nI', v:count1)
onoremap <silent> I& :call targets#o('&cI', v:count1)
onoremap <silent> IL| :call targets#o('|LI', v:count1)
onoremap <silent> IN| :call targets#o('|NI', v:count1)
onoremap <silent> Il| :call targets#o('|lI', v:count1)
onoremap <silent> In| :call targets#o('|nI', v:count1)
onoremap <silent> I| :call targets#o('|cI', v:count1)
onoremap <silent> IL\ :call targets#o('\LI', v:count1)
onoremap <silent> IN\ :call targets#o('\NI', v:count1)
onoremap <silent> Il\ :call targets#o('\lI', v:count1)
onoremap <silent> In\ :call targets#o('\nI', v:count1)
onoremap <silent> I\ :call targets#o('\cI', v:count1)
onoremap <silent> IL/ :call targets#o('/LI', v:count1)
onoremap <silent> IN/ :call targets#o('/NI', v:count1)
onoremap <silent> Il/ :call targets#o('/lI', v:count1)
onoremap <silent> In/ :call targets#o('/nI', v:count1)
onoremap <silent> I/ :call targets#o('/cI', v:count1)
onoremap <silent> IL# :call targets#o('#LI', v:count1)
onoremap <silent> IN# :call targets#o('#NI', v:count1)
onoremap <silent> Il# :call targets#o('#lI', v:count1)
onoremap <silent> In# :call targets#o('#nI', v:count1)
onoremap <silent> I# :call targets#o('#cI', v:count1)
onoremap <silent> IL* :call targets#o('*LI', v:count1)
onoremap <silent> IN* :call targets#o('*NI', v:count1)
onoremap <silent> Il* :call targets#o('*lI', v:count1)
onoremap <silent> In* :call targets#o('*nI', v:count1)
onoremap <silent> I* :call targets#o('*cI', v:count1)
onoremap <silent> IL_ :call targets#o('_LI', v:count1)
onoremap <silent> IN_ :call targets#o('_NI', v:count1)
onoremap <silent> Il_ :call targets#o('_lI', v:count1)
onoremap <silent> In_ :call targets#o('_nI', v:count1)
onoremap <silent> I_ :call targets#o('_cI', v:count1)
onoremap <silent> IL~ :call targets#o('~LI', v:count1)
onoremap <silent> IN~ :call targets#o('~NI', v:count1)
onoremap <silent> Il~ :call targets#o('~lI', v:count1)
onoremap <silent> In~ :call targets#o('~nI', v:count1)
onoremap <silent> I~ :call targets#o('~cI', v:count1)
onoremap <silent> IL= :call targets#o('=LI', v:count1)
onoremap <silent> IN= :call targets#o('=NI', v:count1)
onoremap <silent> Il= :call targets#o('=lI', v:count1)
onoremap <silent> In= :call targets#o('=nI', v:count1)
onoremap <silent> I= :call targets#o('=cI', v:count1)
onoremap <silent> IL- :call targets#o('-LI', v:count1)
onoremap <silent> IN- :call targets#o('-NI', v:count1)
onoremap <silent> Il- :call targets#o('-lI', v:count1)
onoremap <silent> In- :call targets#o('-nI', v:count1)
onoremap <silent> I- :call targets#o('-cI', v:count1)
onoremap <silent> IL+ :call targets#o('+LI', v:count1)
onoremap <silent> IN+ :call targets#o('+NI', v:count1)
onoremap <silent> Il+ :call targets#o('+lI', v:count1)
onoremap <silent> In+ :call targets#o('+nI', v:count1)
onoremap <silent> I+ :call targets#o('+cI', v:count1)
onoremap <silent> IL: :call targets#o(':LI', v:count1)
onoremap <silent> IN: :call targets#o(':NI', v:count1)
onoremap <silent> Il: :call targets#o(':lI', v:count1)
onoremap <silent> In: :call targets#o(':nI', v:count1)
onoremap <silent> I: :call targets#o(':cI', v:count1)
onoremap <silent> IL; :call targets#o(';LI', v:count1)
onoremap <silent> IN; :call targets#o(';NI', v:count1)
onoremap <silent> Il; :call targets#o(';lI', v:count1)
onoremap <silent> In; :call targets#o(';nI', v:count1)
onoremap <silent> I; :call targets#o(';cI', v:count1)
onoremap <silent> IL. :call targets#o('.LI', v:count1)
onoremap <silent> IN. :call targets#o('.NI', v:count1)
onoremap <silent> Il. :call targets#o('.lI', v:count1)
onoremap <silent> In. :call targets#o('.nI', v:count1)
onoremap <silent> I. :call targets#o('.cI', v:count1)
onoremap <silent> IL, :call targets#o(',LI', v:count1)
onoremap <silent> IN, :call targets#o(',NI', v:count1)
onoremap <silent> Il, :call targets#o(',lI', v:count1)
onoremap <silent> In, :call targets#o(',nI', v:count1)
onoremap <silent> I, :call targets#o(',cI', v:count1)
onoremap <silent> Il` :call targets#o('`lI', v:count1)
onoremap <silent> In` :call targets#o('`nI', v:count1)
onoremap <silent> I` :call targets#o('`cI', v:count1)
onoremap <silent> Il' :call targets#o('''lI', v:count1)
onoremap <silent> In' :call targets#o('''nI', v:count1)
onoremap <silent> I' :call targets#o('''cI', v:count1)
onoremap <silent> Il" :call targets#o('"lI', v:count1)
onoremap <silent> In" :call targets#o('"nI', v:count1)
onoremap <silent> I" :call targets#o('"cI', v:count1)
onoremap <silent> Il> :call targets#o('>lI', v:count1)
onoremap <silent> In> :call targets#o('>nI', v:count1)
onoremap <silent> I> :call targets#o('>cI', v:count1)
onoremap <silent> Il< :call targets#o('<lI', v:count1)
onoremap <silent> In< :call targets#o('<nI', v:count1)
onoremap <silent> I< :call targets#o('<cI', v:count1)
onoremap <silent> Il] :call targets#o(']lI', v:count1)
onoremap <silent> In] :call targets#o(']nI', v:count1)
onoremap <silent> I] :call targets#o(']cI', v:count1)
onoremap <silent> Il[ :call targets#o('[lI', v:count1)
onoremap <silent> In[ :call targets#o('[nI', v:count1)
onoremap <silent> I[ :call targets#o('[cI', v:count1)
onoremap <silent> IlB :call targets#o('BlI', v:count1)
onoremap <silent> InB :call targets#o('BnI', v:count1)
onoremap <silent> IB :call targets#o('BcI', v:count1)
onoremap <silent> Il} :call targets#o('}lI', v:count1)
onoremap <silent> In} :call targets#o('}nI', v:count1)
onoremap <silent> I} :call targets#o('}cI', v:count1)
onoremap <silent> Il{ :call targets#o('{lI', v:count1)
onoremap <silent> In{ :call targets#o('{nI', v:count1)
onoremap <silent> I{ :call targets#o('{cI', v:count1)
onoremap <silent> Ilb :call targets#o('blI', v:count1)
onoremap <silent> Inb :call targets#o('bnI', v:count1)
onoremap <silent> Ib :call targets#o('bcI', v:count1)
onoremap <silent> Il) :call targets#o(')lI', v:count1)
onoremap <silent> In) :call targets#o(')nI', v:count1)
onoremap <silent> I) :call targets#o(')cI', v:count1)
onoremap <silent> Il( :call targets#o('(lI', v:count1)
onoremap <silent> In( :call targets#o('(nI', v:count1)
onoremap <silent> I( :call targets#o('(cI', v:count1)
onoremap <silent> Ila :call targets#o('alI', v:count1)
onoremap <silent> Ina :call targets#o('anI', v:count1)
onoremap <silent> Ia :call targets#o('acI', v:count1)
onoremap <silent> Ilt :call targets#o('tlI', v:count1)
onoremap <silent> Int :call targets#o('tnI', v:count1)
onoremap <silent> It :call targets#o('tcI', v:count1)
map J :tabn
map K :tabp
vmap L $
nmap L $
xmap S <Plug>VSurround
xmap X <Plug>(Exchange)
nmap [xx <Plug>unimpaired_line_xml_encode
xmap [x <Plug>unimpaired_xml_encode
nmap [x <Plug>unimpaired_xml_encode
nmap [uu <Plug>unimpaired_line_url_encode
xmap [u <Plug>unimpaired_url_encode
nmap [u <Plug>unimpaired_url_encode
nmap [yy <Plug>unimpaired_line_string_encode
xmap [y <Plug>unimpaired_string_encode
nmap [y <Plug>unimpaired_string_encode
nmap [p <Plug>unimpairedPutAbove
xmap [e <Plug>unimpairedMoveSelectionUp
nmap [e <Plug>unimpairedMoveUp
nmap [  <Plug>unimpairedBlankUp
omap [n <Plug>unimpairedContextPrevious
nmap [n <Plug>unimpairedContextPrevious
nmap [o <Plug>unimpairedOPrevious
nmap [f <Plug>unimpairedDirectoryPrevious
nmap [T <Plug>unimpairedTFirst
nmap [t <Plug>unimpairedTPrevious
nmap [ <Plug>unimpairedQPFile
nmap [Q <Plug>unimpairedQFirst
nmap [q <Plug>unimpairedQPrevious
nmap [ <Plug>unimpairedLPFile
nmap [L <Plug>unimpairedLFirst
nmap [l <Plug>unimpairedLPrevious
nmap [B <Plug>unimpairedBFirst
nmap [b <Plug>unimpairedBPrevious
nmap [A <Plug>unimpairedAFirst
nmap [a <Plug>unimpairedAPrevious
nnoremap <silent> [= :call signature#marker#Goto("prev", "any",  v:count)
nnoremap <silent> [- :call signature#marker#Goto("prev", "same", v:count)
nnoremap <silent> [` :call signature#mark#Goto("prev", "spot", "pos")
nnoremap <silent> [' :call signature#mark#Goto("prev", "line", "pos")
nmap ]xx <Plug>unimpaired_line_xml_decode
xmap ]x <Plug>unimpaired_xml_decode
nmap ]x <Plug>unimpaired_xml_decode
nmap ]uu <Plug>unimpaired_line_url_decode
xmap ]u <Plug>unimpaired_url_decode
nmap ]u <Plug>unimpaired_url_decode
nmap ]yy <Plug>unimpaired_line_string_decode
xmap ]y <Plug>unimpaired_string_decode
nmap ]y <Plug>unimpaired_string_decode
nmap ]p <Plug>unimpairedPutBelow
xmap ]e <Plug>unimpairedMoveSelectionDown
nmap ]e <Plug>unimpairedMoveDown
nmap ]  <Plug>unimpairedBlankDown
omap ]n <Plug>unimpairedContextNext
nmap ]n <Plug>unimpairedContextNext
nmap ]o <Plug>unimpairedONext
nmap ]f <Plug>unimpairedDirectoryNext
nmap ]T <Plug>unimpairedTLast
nmap ]t <Plug>unimpairedTNext
nmap ] <Plug>unimpairedQNFile
nmap ]Q <Plug>unimpairedQLast
nmap ]q <Plug>unimpairedQNext
nmap ] <Plug>unimpairedLNFile
nmap ]L <Plug>unimpairedLLast
nmap ]l <Plug>unimpairedLNext
nmap ]B <Plug>unimpairedBLast
nmap ]b <Plug>unimpairedBNext
nmap ]A <Plug>unimpairedALast
nmap ]a <Plug>unimpairedANext
nnoremap <silent> ]= :call signature#marker#Goto("next", "any",  v:count)
nnoremap <silent> ]- :call signature#marker#Goto("next", "same", v:count)
nnoremap <silent> ]` :call signature#mark#Goto("next", "spot", "pos")
nnoremap <silent> ]' :call signature#mark#Goto("next", "line", "pos")
nnoremap <silent> `[ :call signature#mark#Goto("prev", "spot", "alpha")
nnoremap <silent> `] :call signature#mark#Goto("next", "spot", "alpha")
xnoremap <silent> <expr> a targets#e('a')
onoremap <silent> aL$ :call targets#o('$La', v:count1)
onoremap <silent> aN$ :call targets#o('$Na', v:count1)
onoremap <silent> al$ :call targets#o('$la', v:count1)
onoremap <silent> an$ :call targets#o('$na', v:count1)
onoremap <silent> a$ :call targets#o('$ca', v:count1)
onoremap <silent> aL& :call targets#o('&La', v:count1)
onoremap <silent> aN& :call targets#o('&Na', v:count1)
onoremap <silent> al& :call targets#o('&la', v:count1)
onoremap <silent> an& :call targets#o('&na', v:count1)
onoremap <silent> a& :call targets#o('&ca', v:count1)
onoremap <silent> aL| :call targets#o('|La', v:count1)
onoremap <silent> aN| :call targets#o('|Na', v:count1)
onoremap <silent> al| :call targets#o('|la', v:count1)
onoremap <silent> an| :call targets#o('|na', v:count1)
onoremap <silent> a| :call targets#o('|ca', v:count1)
onoremap <silent> aL\ :call targets#o('\La', v:count1)
onoremap <silent> aN\ :call targets#o('\Na', v:count1)
onoremap <silent> al\ :call targets#o('\la', v:count1)
onoremap <silent> an\ :call targets#o('\na', v:count1)
onoremap <silent> a\ :call targets#o('\ca', v:count1)
onoremap <silent> aL/ :call targets#o('/La', v:count1)
onoremap <silent> aN/ :call targets#o('/Na', v:count1)
onoremap <silent> al/ :call targets#o('/la', v:count1)
onoremap <silent> an/ :call targets#o('/na', v:count1)
onoremap <silent> a/ :call targets#o('/ca', v:count1)
onoremap <silent> aL# :call targets#o('#La', v:count1)
onoremap <silent> aN# :call targets#o('#Na', v:count1)
onoremap <silent> al# :call targets#o('#la', v:count1)
onoremap <silent> an# :call targets#o('#na', v:count1)
onoremap <silent> a# :call targets#o('#ca', v:count1)
onoremap <silent> aL* :call targets#o('*La', v:count1)
onoremap <silent> aN* :call targets#o('*Na', v:count1)
onoremap <silent> al* :call targets#o('*la', v:count1)
onoremap <silent> an* :call targets#o('*na', v:count1)
onoremap <silent> a* :call targets#o('*ca', v:count1)
onoremap <silent> aL_ :call targets#o('_La', v:count1)
onoremap <silent> aN_ :call targets#o('_Na', v:count1)
onoremap <silent> al_ :call targets#o('_la', v:count1)
onoremap <silent> an_ :call targets#o('_na', v:count1)
onoremap <silent> a_ :call targets#o('_ca', v:count1)
onoremap <silent> aL~ :call targets#o('~La', v:count1)
onoremap <silent> aN~ :call targets#o('~Na', v:count1)
onoremap <silent> al~ :call targets#o('~la', v:count1)
onoremap <silent> an~ :call targets#o('~na', v:count1)
onoremap <silent> a~ :call targets#o('~ca', v:count1)
onoremap <silent> aL= :call targets#o('=La', v:count1)
onoremap <silent> aN= :call targets#o('=Na', v:count1)
onoremap <silent> al= :call targets#o('=la', v:count1)
onoremap <silent> an= :call targets#o('=na', v:count1)
onoremap <silent> a= :call targets#o('=ca', v:count1)
onoremap <silent> aL- :call targets#o('-La', v:count1)
onoremap <silent> aN- :call targets#o('-Na', v:count1)
onoremap <silent> al- :call targets#o('-la', v:count1)
onoremap <silent> an- :call targets#o('-na', v:count1)
onoremap <silent> a- :call targets#o('-ca', v:count1)
onoremap <silent> aL+ :call targets#o('+La', v:count1)
onoremap <silent> aN+ :call targets#o('+Na', v:count1)
onoremap <silent> al+ :call targets#o('+la', v:count1)
onoremap <silent> an+ :call targets#o('+na', v:count1)
onoremap <silent> a+ :call targets#o('+ca', v:count1)
onoremap <silent> aL: :call targets#o(':La', v:count1)
onoremap <silent> aN: :call targets#o(':Na', v:count1)
onoremap <silent> al: :call targets#o(':la', v:count1)
onoremap <silent> an: :call targets#o(':na', v:count1)
onoremap <silent> a: :call targets#o(':ca', v:count1)
onoremap <silent> aL; :call targets#o(';La', v:count1)
onoremap <silent> aN; :call targets#o(';Na', v:count1)
onoremap <silent> al; :call targets#o(';la', v:count1)
onoremap <silent> an; :call targets#o(';na', v:count1)
onoremap <silent> a; :call targets#o(';ca', v:count1)
onoremap <silent> aL. :call targets#o('.La', v:count1)
onoremap <silent> aN. :call targets#o('.Na', v:count1)
onoremap <silent> al. :call targets#o('.la', v:count1)
onoremap <silent> an. :call targets#o('.na', v:count1)
onoremap <silent> a. :call targets#o('.ca', v:count1)
onoremap <silent> aL, :call targets#o(',La', v:count1)
onoremap <silent> aN, :call targets#o(',Na', v:count1)
onoremap <silent> al, :call targets#o(',la', v:count1)
onoremap <silent> an, :call targets#o(',na', v:count1)
onoremap <silent> a, :call targets#o(',ca', v:count1)
onoremap <silent> al` :call targets#o('`la', v:count1)
onoremap <silent> an` :call targets#o('`na', v:count1)
onoremap <silent> a` :call targets#o('`ca', v:count1)
onoremap <silent> al' :call targets#o('''la', v:count1)
onoremap <silent> an' :call targets#o('''na', v:count1)
onoremap <silent> a' :call targets#o('''ca', v:count1)
onoremap <silent> al" :call targets#o('"la', v:count1)
onoremap <silent> an" :call targets#o('"na', v:count1)
onoremap <silent> a" :call targets#o('"ca', v:count1)
onoremap <silent> al> :call targets#o('>la', v:count1)
onoremap <silent> an> :call targets#o('>na', v:count1)
onoremap <silent> a> :call targets#o('>ca', v:count1)
onoremap <silent> al< :call targets#o('<la', v:count1)
onoremap <silent> an< :call targets#o('<na', v:count1)
onoremap <silent> a< :call targets#o('<ca', v:count1)
onoremap <silent> al] :call targets#o(']la', v:count1)
onoremap <silent> an] :call targets#o(']na', v:count1)
onoremap <silent> a] :call targets#o(']ca', v:count1)
onoremap <silent> al[ :call targets#o('[la', v:count1)
onoremap <silent> an[ :call targets#o('[na', v:count1)
onoremap <silent> a[ :call targets#o('[ca', v:count1)
onoremap <silent> alB :call targets#o('Bla', v:count1)
onoremap <silent> anB :call targets#o('Bna', v:count1)
onoremap <silent> aB :call targets#o('Bca', v:count1)
onoremap <silent> al} :call targets#o('}la', v:count1)
onoremap <silent> an} :call targets#o('}na', v:count1)
onoremap <silent> a} :call targets#o('}ca', v:count1)
onoremap <silent> al{ :call targets#o('{la', v:count1)
onoremap <silent> an{ :call targets#o('{na', v:count1)
onoremap <silent> a{ :call targets#o('{ca', v:count1)
onoremap <silent> alb :call targets#o('bla', v:count1)
onoremap <silent> anb :call targets#o('bna', v:count1)
onoremap <silent> ab :call targets#o('bca', v:count1)
onoremap <silent> al) :call targets#o(')la', v:count1)
onoremap <silent> an) :call targets#o(')na', v:count1)
onoremap <silent> a) :call targets#o(')ca', v:count1)
onoremap <silent> al( :call targets#o('(la', v:count1)
onoremap <silent> an( :call targets#o('(na', v:count1)
onoremap <silent> a( :call targets#o('(ca', v:count1)
onoremap <silent> ala :call targets#o('ala', v:count1)
onoremap <silent> ana :call targets#o('ana', v:count1)
onoremap <silent> aa :call targets#o('aca', v:count1)
onoremap <silent> alt :call targets#o('tla', v:count1)
onoremap <silent> ant :call targets#o('tna', v:count1)
onoremap <silent> at :call targets#o('tca', v:count1)
nmap cxx <Plug>(ExchangeLine)
nmap cxc <Plug>(ExchangeClear)
nmap cx <Plug>(Exchange)
nmap cS <Plug>CSurround
nmap cs <Plug>Csurround
nmap cgc <Plug>ChangeCommentary
nmap cr <Plug>Coerce
nmap ds <Plug>Dsurround
nnoremap <silent> dm :call signature#utils#Remove(v:count)
vmap gx <Plug>NetrwBrowseXVis
nmap gx <Plug>NetrwBrowseX
xmap gS <Plug>VgSurround
xmap gr <Plug>ReplaceWithRegisterVisual
nmap grr <Plug>ReplaceWithRegisterLine
nmap gr <Plug>ReplaceWithRegisterOperator
nmap gcu <Plug>Commentary<Plug>Commentary
nmap gcc <Plug>CommentaryLine
omap gc <Plug>Commentary
nmap gc <Plug>Commentary
xmap gc <Plug>Commentary
xnoremap <silent> <expr> i targets#e('i')
onoremap <silent> iL$ :call targets#o('$Li', v:count1)
onoremap <silent> iN$ :call targets#o('$Ni', v:count1)
onoremap <silent> il$ :call targets#o('$li', v:count1)
onoremap <silent> in$ :call targets#o('$ni', v:count1)
onoremap <silent> i$ :call targets#o('$ci', v:count1)
onoremap <silent> iL& :call targets#o('&Li', v:count1)
onoremap <silent> iN& :call targets#o('&Ni', v:count1)
onoremap <silent> il& :call targets#o('&li', v:count1)
onoremap <silent> in& :call targets#o('&ni', v:count1)
onoremap <silent> i& :call targets#o('&ci', v:count1)
onoremap <silent> iL| :call targets#o('|Li', v:count1)
onoremap <silent> iN| :call targets#o('|Ni', v:count1)
onoremap <silent> il| :call targets#o('|li', v:count1)
onoremap <silent> in| :call targets#o('|ni', v:count1)
onoremap <silent> i| :call targets#o('|ci', v:count1)
onoremap <silent> iL\ :call targets#o('\Li', v:count1)
onoremap <silent> iN\ :call targets#o('\Ni', v:count1)
onoremap <silent> il\ :call targets#o('\li', v:count1)
onoremap <silent> in\ :call targets#o('\ni', v:count1)
onoremap <silent> i\ :call targets#o('\ci', v:count1)
onoremap <silent> iL/ :call targets#o('/Li', v:count1)
onoremap <silent> iN/ :call targets#o('/Ni', v:count1)
onoremap <silent> il/ :call targets#o('/li', v:count1)
onoremap <silent> in/ :call targets#o('/ni', v:count1)
onoremap <silent> i/ :call targets#o('/ci', v:count1)
onoremap <silent> iL# :call targets#o('#Li', v:count1)
onoremap <silent> iN# :call targets#o('#Ni', v:count1)
onoremap <silent> il# :call targets#o('#li', v:count1)
onoremap <silent> in# :call targets#o('#ni', v:count1)
onoremap <silent> i# :call targets#o('#ci', v:count1)
onoremap <silent> iL* :call targets#o('*Li', v:count1)
onoremap <silent> iN* :call targets#o('*Ni', v:count1)
onoremap <silent> il* :call targets#o('*li', v:count1)
onoremap <silent> in* :call targets#o('*ni', v:count1)
onoremap <silent> i* :call targets#o('*ci', v:count1)
onoremap <silent> iL_ :call targets#o('_Li', v:count1)
onoremap <silent> iN_ :call targets#o('_Ni', v:count1)
onoremap <silent> il_ :call targets#o('_li', v:count1)
onoremap <silent> in_ :call targets#o('_ni', v:count1)
onoremap <silent> i_ :call targets#o('_ci', v:count1)
onoremap <silent> iL~ :call targets#o('~Li', v:count1)
onoremap <silent> iN~ :call targets#o('~Ni', v:count1)
onoremap <silent> il~ :call targets#o('~li', v:count1)
onoremap <silent> in~ :call targets#o('~ni', v:count1)
onoremap <silent> i~ :call targets#o('~ci', v:count1)
onoremap <silent> iL= :call targets#o('=Li', v:count1)
onoremap <silent> iN= :call targets#o('=Ni', v:count1)
onoremap <silent> il= :call targets#o('=li', v:count1)
onoremap <silent> in= :call targets#o('=ni', v:count1)
onoremap <silent> i= :call targets#o('=ci', v:count1)
onoremap <silent> iL- :call targets#o('-Li', v:count1)
onoremap <silent> iN- :call targets#o('-Ni', v:count1)
onoremap <silent> il- :call targets#o('-li', v:count1)
onoremap <silent> in- :call targets#o('-ni', v:count1)
onoremap <silent> i- :call targets#o('-ci', v:count1)
onoremap <silent> iL+ :call targets#o('+Li', v:count1)
onoremap <silent> iN+ :call targets#o('+Ni', v:count1)
onoremap <silent> il+ :call targets#o('+li', v:count1)
onoremap <silent> in+ :call targets#o('+ni', v:count1)
onoremap <silent> i+ :call targets#o('+ci', v:count1)
onoremap <silent> iL: :call targets#o(':Li', v:count1)
onoremap <silent> iN: :call targets#o(':Ni', v:count1)
onoremap <silent> il: :call targets#o(':li', v:count1)
onoremap <silent> in: :call targets#o(':ni', v:count1)
onoremap <silent> i: :call targets#o(':ci', v:count1)
onoremap <silent> iL; :call targets#o(';Li', v:count1)
onoremap <silent> iN; :call targets#o(';Ni', v:count1)
onoremap <silent> il; :call targets#o(';li', v:count1)
onoremap <silent> in; :call targets#o(';ni', v:count1)
onoremap <silent> i; :call targets#o(';ci', v:count1)
onoremap <silent> iL. :call targets#o('.Li', v:count1)
onoremap <silent> iN. :call targets#o('.Ni', v:count1)
onoremap <silent> il. :call targets#o('.li', v:count1)
onoremap <silent> in. :call targets#o('.ni', v:count1)
onoremap <silent> i. :call targets#o('.ci', v:count1)
onoremap <silent> iL, :call targets#o(',Li', v:count1)
onoremap <silent> iN, :call targets#o(',Ni', v:count1)
onoremap <silent> il, :call targets#o(',li', v:count1)
onoremap <silent> in, :call targets#o(',ni', v:count1)
onoremap <silent> i, :call targets#o(',ci', v:count1)
onoremap <silent> il` :call targets#o('`li', v:count1)
onoremap <silent> in` :call targets#o('`ni', v:count1)
onoremap <silent> i` :call targets#o('`ci', v:count1)
onoremap <silent> il' :call targets#o('''li', v:count1)
onoremap <silent> in' :call targets#o('''ni', v:count1)
onoremap <silent> i' :call targets#o('''ci', v:count1)
onoremap <silent> il" :call targets#o('"li', v:count1)
onoremap <silent> in" :call targets#o('"ni', v:count1)
onoremap <silent> i" :call targets#o('"ci', v:count1)
onoremap <silent> il> :call targets#o('>li', v:count1)
onoremap <silent> in> :call targets#o('>ni', v:count1)
onoremap <silent> i> :call targets#o('>ci', v:count1)
onoremap <silent> il< :call targets#o('<li', v:count1)
onoremap <silent> in< :call targets#o('<ni', v:count1)
onoremap <silent> i< :call targets#o('<ci', v:count1)
onoremap <silent> il] :call targets#o(']li', v:count1)
onoremap <silent> in] :call targets#o(']ni', v:count1)
onoremap <silent> i] :call targets#o(']ci', v:count1)
onoremap <silent> il[ :call targets#o('[li', v:count1)
onoremap <silent> in[ :call targets#o('[ni', v:count1)
onoremap <silent> i[ :call targets#o('[ci', v:count1)
onoremap <silent> ilB :call targets#o('Bli', v:count1)
onoremap <silent> inB :call targets#o('Bni', v:count1)
onoremap <silent> iB :call targets#o('Bci', v:count1)
onoremap <silent> il} :call targets#o('}li', v:count1)
onoremap <silent> in} :call targets#o('}ni', v:count1)
onoremap <silent> i} :call targets#o('}ci', v:count1)
onoremap <silent> il{ :call targets#o('{li', v:count1)
onoremap <silent> in{ :call targets#o('{ni', v:count1)
onoremap <silent> i{ :call targets#o('{ci', v:count1)
onoremap <silent> ilb :call targets#o('bli', v:count1)
onoremap <silent> inb :call targets#o('bni', v:count1)
onoremap <silent> ib :call targets#o('bci', v:count1)
onoremap <silent> il) :call targets#o(')li', v:count1)
onoremap <silent> in) :call targets#o(')ni', v:count1)
onoremap <silent> i) :call targets#o(')ci', v:count1)
onoremap <silent> il( :call targets#o('(li', v:count1)
onoremap <silent> in( :call targets#o('(ni', v:count1)
onoremap <silent> i( :call targets#o('(ci', v:count1)
onoremap <silent> ila :call targets#o('ali', v:count1)
onoremap <silent> ina :call targets#o('ani', v:count1)
onoremap <silent> ia :call targets#o('aci', v:count1)
onoremap <silent> ilt :call targets#o('tli', v:count1)
onoremap <silent> int :call targets#o('tni', v:count1)
onoremap <silent> it :call targets#o('tci', v:count1)
nnoremap <silent> m? :call signature#marker#List(v:count, 0)
nnoremap <silent> m/ :call signature#mark#List(0, 0)
nnoremap <silent> m<BS> :call signature#marker#Purge()
nnoremap <silent> m  :call signature#mark#Purge("all")
nnoremap <silent> m- :call signature#mark#Purge("line")
nnoremap <silent> m. :call signature#mark#ToggleAtLine()
nnoremap <silent> m, :call signature#mark#Toggle("next")
nnoremap <silent> m :call signature#utils#Input()
nmap ySS <Plug>YSsurround
nmap ySs <Plug>YSsurround
nmap yss <Plug>Yssurround
nmap yS <Plug>YSurround
nmap ys <Plug>Ysurround
noremap <silent> <Plug>AirlineSelectTab1 :1tabn
noremap <silent> <Plug>AirlineSelectTab2 :2tabn
noremap <silent> <Plug>AirlineSelectTab3 :3tabn
noremap <silent> <Plug>AirlineSelectTab4 :4tabn
noremap <silent> <Plug>AirlineSelectTab5 :5tabn
noremap <silent> <Plug>AirlineSelectTab6 :6tabn
noremap <silent> <Plug>AirlineSelectTab7 :7tabn
noremap <silent> <Plug>AirlineSelectTab8 :8tabn
noremap <silent> <Plug>AirlineSelectTab9 :9tabn
noremap <silent> <Plug>AirlineSelectPrevTab gT
noremap <silent> <Plug>AirlineSelectNextTab :exe repeat(':tabn|', v:count1)
vnoremap <silent> <Plug>NetrwBrowseXVis :call netrw#BrowseXVis()
nnoremap <silent> <Plug>NetrwBrowseX :call netrw#BrowseX(expand((exists("g:netrw_gx")? g:netrw_gx : '<cfile>')),netrw#CheckIfRemote())
nnoremap <silent> <Plug>SurroundRepeat .
nnoremap <silent> <Plug>ReplaceWithRegisterVisual :call setline('.', getline('.'))|execute 'silent! call repeat#setreg("\<Plug>ReplaceWithRegisterVisual", v:register)'|call ReplaceWithRegister#SetRegister()|if ReplaceWithRegister#IsExprReg()|    let g:ReplaceWithRegister_expr = getreg('=')|endif|execute 'normal!' ReplaceWithRegister#VisualMode()|call ReplaceWithRegister#Operator('visual', "\<Plug>ReplaceWithRegisterVisual")
vnoremap <silent> <Plug>ReplaceWithRegisterVisual :call setline('.', getline('.'))|execute 'silent! call repeat#setreg("\<Plug>ReplaceWithRegisterVisual", v:register)'|call ReplaceWithRegister#SetRegister()|if ReplaceWithRegister#IsExprReg()|    let g:ReplaceWithRegister_expr = getreg('=')|endif|call ReplaceWithRegister#Operator('visual', "\<Plug>ReplaceWithRegisterVisual")
nnoremap <silent> <Plug>ReplaceWithRegisterLine :call setline('.', getline('.'))|execute 'silent! call repeat#setreg("\<Plug>ReplaceWithRegisterLine", v:register)'|call ReplaceWithRegister#SetRegister()|if ReplaceWithRegister#IsExprReg()|    let g:ReplaceWithRegister_expr = getreg('=')|endif|execute 'normal! V' . v:count1 . "_\<Esc>"|call ReplaceWithRegister#Operator('visual', "\<Plug>ReplaceWithRegisterLine")
nnoremap <silent> <Plug>ReplaceWithRegisterExpressionSpecial :let g:ReplaceWithRegister_expr = getreg('=')|execute 'normal!' v:count1 . '.'
nnoremap <expr> <Plug>ReplaceWithRegisterOperator ReplaceWithRegister#OperatorExpression()
snoremap <silent> <Del> c
snoremap <silent> <BS> c
nmap <silent> <Plug>CommentaryUndo <Plug>Commentary<Plug>Commentary
nnoremap <silent> <Plug>(ctrlp) :CtrlP
nmap <silent> <Plug>unimpairedOPrevious <Plug>unimpairedDirectoryPrevious:echohl WarningMSG|echo "[o is deprecated. Use [f"|echohl NONE
nmap <silent> <Plug>unimpairedONext <Plug>unimpairedDirectoryNext:echohl WarningMSG|echo "]o is deprecated. Use ]f"|echohl NONE
nnoremap <silent> <Plug>unimpairedTLast :exe "".(v:count ? v:count : "")."tlast"
nnoremap <silent> <Plug>unimpairedTFirst :exe "".(v:count ? v:count : "")."tfirst"
nnoremap <silent> <Plug>unimpairedTNext :exe "".(v:count ? v:count : "")."tnext"
nnoremap <silent> <Plug>unimpairedTPrevious :exe "".(v:count ? v:count : "")."tprevious"
nnoremap <silent> <Plug>unimpairedQNFile :exe "".(v:count ? v:count : "")."cnfile"zv
nnoremap <silent> <Plug>unimpairedQPFile :exe "".(v:count ? v:count : "")."cpfile"zv
nnoremap <silent> <Plug>unimpairedQLast :exe "".(v:count ? v:count : "")."clast"zv
nnoremap <silent> <Plug>unimpairedQFirst :exe "".(v:count ? v:count : "")."cfirst"zv
nnoremap <silent> <Plug>unimpairedQNext :exe "".(v:count ? v:count : "")."cnext"zv
nnoremap <silent> <Plug>unimpairedQPrevious :exe "".(v:count ? v:count : "")."cprevious"zv
nnoremap <silent> <Plug>unimpairedLNFile :exe "".(v:count ? v:count : "")."lnfile"zv
nnoremap <silent> <Plug>unimpairedLPFile :exe "".(v:count ? v:count : "")."lpfile"zv
nnoremap <silent> <Plug>unimpairedLLast :exe "".(v:count ? v:count : "")."llast"zv
nnoremap <silent> <Plug>unimpairedLFirst :exe "".(v:count ? v:count : "")."lfirst"zv
nnoremap <silent> <Plug>unimpairedLNext :exe "".(v:count ? v:count : "")."lnext"zv
nnoremap <silent> <Plug>unimpairedLPrevious :exe "".(v:count ? v:count : "")."lprevious"zv
nnoremap <silent> <Plug>unimpairedBLast :exe "".(v:count ? v:count : "")."blast"
nnoremap <silent> <Plug>unimpairedBFirst :exe "".(v:count ? v:count : "")."bfirst"
nnoremap <silent> <Plug>unimpairedBNext :exe "".(v:count ? v:count : "")."bnext"
nnoremap <silent> <Plug>unimpairedBPrevious :exe "".(v:count ? v:count : "")."bprevious"
nnoremap <silent> <Plug>unimpairedALast :exe "".(v:count ? v:count : "")."last"
nnoremap <silent> <Plug>unimpairedAFirst :exe "".(v:count ? v:count : "")."first"
nnoremap <silent> <Plug>unimpairedANext :exe "".(v:count ? v:count : "")."next"
nnoremap <silent> <Plug>unimpairedAPrevious :exe "".(v:count ? v:count : "")."previous"
nnoremap <Plug>GoldenViewSwitchWithSmallest :call GoldenView#zl#window#switch_buffer_with_smallest()
nnoremap <Plug>GoldenViewSwitchWithLargest :call GoldenView#zl#window#switch_buffer_with_largest()
nnoremap <Plug>GoldenViewSwitchToggle :call GoldenView#zl#window#switch_buffer_toggle()
nnoremap <Plug>GoldenViewSwitchMain :call GoldenView#SwitchMain()
nnoremap <Plug>GoldenViewPrevious :call GoldenView#zl#window#previous_window_or_tab()
nnoremap <Plug>GoldenViewNext :call GoldenView#zl#window#next_window_or_tab()
nnoremap <Plug>GoldenViewSplit :call GoldenView#Split()
nnoremap <Plug>GoldenViewResize :GoldenViewResize
nnoremap <Plug>ToggleGoldenViewAutoResize :ToggleGoldenViewAutoResize
nnoremap <silent> <Plug>(startify-open-buffers) :call startify#open_buffers()
nnoremap <SNR>31_: :=v:count ? v:count : ''
nnoremap <F5> :YcmForceCompileAndDiagnostics :lop
nmap <F8> :TagbarToggle   
imap S <Plug>ISurround
imap s <Plug>Isurround
inoremap <silent> 	 =UltiSnips#ExpandSnippet()
inoremap <expr> <NL> ((pumvisible())?("\"):("\<NL>"))
inoremap <expr>  ((pumvisible() && !empty(v:completed_item))?("\"):("\"))
inoremap <silent>  =UltiSnips#ListSnippets()
inoremap <expr>  pumvisible() ? "\" : "\"
inoremap <expr>  pumvisible() ? "\" : "\"
imap  <Plug>Isurround
imap ,{ {}i
imap ,( ()i
inoremap <expr> j ((pumvisible() && !empty(v:completed_item))?("\"):("j"))
imap <expr> jk (pumvisible()?(empty(v:completed_item)?("l"):("\\")):("\l"))
inoremap <expr> k ((pumvisible() && !empty(v:completed_item))?("\"):("k"))
cabbr vsprosed =(getcmdtype()==':' && getcmdpos()==1 ? 'VspRosed' : 'vsprosed')
cabbr sprosed =(getcmdtype()==':' && getcmdpos()==1 ? 'SpRosed' : 'sprosed')
cabbr tabrosed =(getcmdtype()==':' && getcmdpos()==1 ? 'TabRosed' : 'tabrosed')
cabbr rosed =(getcmdtype()==':' && getcmdpos()==1 ? 'Rosed' : 'rosed')
cabbr roscd =(getcmdtype()==':' && getcmdpos()==1 ? 'Roscd' : 'roscd')
let &cpo=s:cpo_save
unlet s:cpo_save
set autoindent
set background=dark
set backspace=indent,eol,start
set clipboard=unnamedplus
set completefunc=youcompleteme#Complete
set completeopt=menuone,noinsert,preview
set cpoptions=aAceFsB
set eadirection=ver
set expandtab
set fileencodings=ucs-bom,utf-8,default,latin1
set grepprg=grep\ -nH\ $*
set helplang=en
set hlsearch
set ignorecase
set incsearch
set laststatus=2
set makeprg=catkin\ build\ mrs_trackers
set omnifunc=youcompleteme#OmniComplete
set path=.,/usr/include,,,~/git/**,~/.vim/UltiSnips/**
set runtimepath=~/.vim,~/.vim/plugged/jellybeans.vim/,~/.vim/plugged/vim-fugitive/,~/.vim/plugged/vim-airline/,~/.vim/plugged/vim-airline-themes/,~/.vim/plugged/vimux/,~/.vim/plugged/nerdtree/,~/.vim/plugged/vim-startify/,~/.vim/plugged/vim-signature/,~/.vim/plugged/vim-abolish/,~/.vim/plugged/vim-argwrap/,~/.vim/plugged/vim-python-pep8-indent/,~/.vim/plugged/GoldenView.Vim/,~/.vim/plugged/quick-scope/,~/.vim/plugged/tagbar/,~/.vim/plugged/youcompleteme/,~/.vim/plugged/vim-ros/,~/.vim/plugged/tmuxline.vim/,~/.vim/plugged/vimtex/,~/.vim/plugged/vimwiki/,~/.vim/plugged/MatlabFilesEdition/,~/.vim/plugged/vim-tmux-navigator/,~/.vim/plugged/supertab/,~/.vim/plugged/vim-unimpaired/,~/.vim/plugged/ctrlp.vim/,~/.vim/plugged/vim-repeat/,~/.vim/plugged/vim-commentary/,~/.vim/plugged/vim-multiple-cursors/,~/.vim/plugged/united-front/,~/.vim/plugged/ultisnips/,~/.vim/plugged/targets.vim/,~/.vim/plugged/ReplaceWithRegister/,~/.vim/plugged/vim-surround/,~/.vim/plugged/vim-exchange/,/usr/share/vim/vimfiles,/usr/share/vim/vim80,/usr/share/vim/vimfiles/after,~/.vim/plugged/vim-signature/after,~/.vim/plugged/vimtex/after,~/.vim/plugged/ultisnips/after,~/.vim/after
set scrolloff=10
set shiftwidth=2
set shortmess=filnxtToOIc
set showmatch
set showtabline=2
set smartcase
set smartindent
set softtabstop=2
set splitbelow
set splitright
set synmaxcol=200
set tabline=%!airline#extensions#tabline#get()
set tabstop=2
set tags=./tags,./TAGS,tags,TAGS,~/tags,~/tags-once
set title
set updatetime=200
set wildmenu
set winheight=4
set winminheight=4
set winminwidth=26
set winwidth=26
let s:so_save = &so | let s:siso_save = &siso | set so=0 siso=0
let v:this_session=expand("<sfile>:p")
silent only
cd ~/git/uav_core/ros_nodes/mrs_trackers
if expand('%') == '' && !&modified && line('$') <= 1 && getline(1) == ''
  let s:wipebuf = bufnr('%')
endif
set shortmess=aoO
badd +1 src/mrs_trackers/mpc_tracker.cpp
badd +1 config/simulation.yaml
badd +1 config/f550.yaml
argglobal
silent! argdel *
$argadd src/mrs_trackers/mpc_tracker.cpp
edit src/mrs_trackers/mpc_tracker.cpp
set splitbelow splitright
wincmd t
set winminheight=1 winheight=1 winminwidth=1 winwidth=1
argglobal
setlocal keymap=
setlocal noarabic
setlocal autoindent
setlocal backupcopy=
setlocal balloonexpr=
setlocal nobinary
setlocal nobreakindent
setlocal breakindentopt=
setlocal bufhidden=
setlocal buflisted
setlocal buftype=
setlocal cindent
setlocal cinkeys=0{,0},0),:,0#,!^F,o,O,e
setlocal cinoptions=
setlocal cinwords=if,else,while,do,for,switch
setlocal colorcolumn=
setlocal comments=sO:*\ -,mO:*\ \ ,exO:*/,s1:/*,mb:*,ex:*/,://
setlocal commentstring=/*%s*/
setlocal complete=.,w,b,u,t,i
setlocal concealcursor=
setlocal conceallevel=0
setlocal completefunc=youcompleteme#Complete
setlocal nocopyindent
setlocal cryptmethod=
setlocal nocursorbind
setlocal nocursorcolumn
setlocal nocursorline
setlocal define=
setlocal dictionary=
setlocal nodiff
setlocal equalprg=
setlocal errorformat=
setlocal expandtab
if &filetype != 'cpp'
setlocal filetype=cpp
endif
setlocal fixendofline
setlocal foldcolumn=0
setlocal foldenable
setlocal foldexpr=0
setlocal foldignore=#
setlocal foldlevel=0
set foldmarker=//{,//}
setlocal foldmarker=//{,//}
set foldmethod=marker
setlocal foldmethod=marker
setlocal foldminlines=1
setlocal foldnestmax=20
setlocal foldtext=foldtext()
setlocal formatexpr=
setlocal formatoptions=croql
setlocal formatlistpat=^\\s*\\d\\+[\\]:.)}\\t\ ]\\s*
setlocal formatprg=
setlocal grepprg=
setlocal iminsert=2
setlocal imsearch=2
setlocal include=
setlocal includeexpr=
setlocal indentexpr=
setlocal indentkeys=0{,0},:,0#,!^F,o,O,e
setlocal noinfercase
setlocal iskeyword=@,48-57,_,192-255
setlocal keywordprg=
set linebreak
setlocal linebreak
setlocal nolisp
setlocal lispwords=
setlocal nolist
setlocal makeencoding=
setlocal makeprg=
setlocal matchpairs=(:),{:},[:]
setlocal modeline
setlocal modifiable
setlocal nrformats=bin,octal,hex
set number
setlocal number
setlocal numberwidth=4
setlocal omnifunc=youcompleteme#OmniComplete
setlocal path=
setlocal nopreserveindent
setlocal nopreviewwindow
setlocal quoteescape=\\
setlocal noreadonly
set relativenumber
setlocal relativenumber
setlocal norightleft
setlocal rightleftcmd=search
setlocal noscrollbind
setlocal shiftwidth=2
setlocal noshortname
setlocal signcolumn=auto
setlocal smartindent
setlocal softtabstop=2
setlocal nospell
setlocal spellcapcheck=[.?!]\\_[\\])'\"\	\ ]\\+
setlocal spellfile=
setlocal spelllang=en
setlocal statusline=%!airline#statusline(1)
setlocal suffixesadd=
setlocal swapfile
setlocal synmaxcol=200
if &syntax != 'cpp'
setlocal syntax=cpp
endif
setlocal tabstop=2
setlocal tagcase=
setlocal tags=
setlocal textwidth=0
setlocal thesaurus=
setlocal noundofile
setlocal undolevels=-123456
setlocal nowinfixheight
setlocal nowinfixwidth
setlocal wrap
setlocal wrapmargin=0
let s:l = 1 - ((0 * winheight(0) + 23) / 46)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
1
normal! 0
tabedit config/simulation.yaml
set splitbelow splitright
wincmd _ | wincmd |
vsplit
1wincmd h
wincmd w
wincmd t
set winminheight=1 winheight=1 winminwidth=1 winwidth=1
exe 'vert 1resize ' . ((&columns * 106 + 87) / 174)
exe 'vert 2resize ' . ((&columns * 67 + 87) / 174)
argglobal
setlocal keymap=
setlocal noarabic
setlocal autoindent
setlocal backupcopy=
setlocal balloonexpr=
setlocal nobinary
setlocal nobreakindent
setlocal breakindentopt=
setlocal bufhidden=
setlocal buflisted
setlocal buftype=
setlocal nocindent
setlocal cinkeys=0{,0},0),:,0#,!^F,o,O,e
setlocal cinoptions=
setlocal cinwords=if,else,while,do,for,switch
setlocal colorcolumn=
setlocal comments=:#
setlocal commentstring=#\ %s
setlocal complete=.,w,b,u,t,i
setlocal concealcursor=
setlocal conceallevel=0
setlocal completefunc=youcompleteme#Complete
setlocal nocopyindent
setlocal cryptmethod=
setlocal nocursorbind
setlocal nocursorcolumn
setlocal nocursorline
setlocal define=
setlocal dictionary=
setlocal nodiff
setlocal equalprg=
setlocal errorformat=
setlocal expandtab
if &filetype != 'yaml'
setlocal filetype=yaml
endif
setlocal fixendofline
setlocal foldcolumn=0
setlocal foldenable
setlocal foldexpr=0
setlocal foldignore=#
setlocal foldlevel=0
set foldmarker=#{,#}
setlocal foldmarker=#{,#}
set foldmethod=marker
setlocal foldmethod=marker
setlocal foldminlines=1
setlocal foldnestmax=20
setlocal foldtext=foldtext()
setlocal formatexpr=
setlocal formatoptions=croql
setlocal formatlistpat=^\\s*\\d\\+[\\]:.)}\\t\ ]\\s*
setlocal formatprg=
setlocal grepprg=
setlocal iminsert=2
setlocal imsearch=2
setlocal include=
setlocal includeexpr=
setlocal indentexpr=GetYAMLIndent(v:lnum)
setlocal indentkeys=!^F,o,O,0#,0},0],<:>,0-
setlocal noinfercase
setlocal iskeyword=@,48-57,_,192-255
setlocal keywordprg=
set linebreak
setlocal linebreak
setlocal nolisp
setlocal lispwords=
setlocal nolist
setlocal makeencoding=
setlocal makeprg=
setlocal matchpairs=(:),{:},[:]
setlocal modeline
setlocal modifiable
setlocal nrformats=bin,octal,hex
set number
setlocal number
setlocal numberwidth=4
setlocal omnifunc=
setlocal path=
setlocal nopreserveindent
setlocal nopreviewwindow
setlocal quoteescape=\\
setlocal noreadonly
set relativenumber
setlocal relativenumber
setlocal norightleft
setlocal rightleftcmd=search
setlocal noscrollbind
setlocal shiftwidth=2
setlocal noshortname
setlocal signcolumn=auto
setlocal nosmartindent
setlocal softtabstop=2
setlocal nospell
setlocal spellcapcheck=[.?!]\\_[\\])'\"\	\ ]\\+
setlocal spellfile=
setlocal spelllang=en
setlocal statusline=%!airline#statusline(1)
setlocal suffixesadd=
setlocal swapfile
setlocal synmaxcol=200
if &syntax != 'yaml'
setlocal syntax=yaml
endif
setlocal tabstop=2
setlocal tagcase=
setlocal tags=
setlocal textwidth=0
setlocal thesaurus=
setlocal noundofile
setlocal undolevels=-123456
setlocal nowinfixheight
setlocal nowinfixwidth
setlocal wrap
setlocal wrapmargin=0
let s:l = 1 - ((0 * winheight(0) + 23) / 46)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
1
normal! 0
wincmd w
argglobal
edit config/f550.yaml
setlocal keymap=
setlocal noarabic
setlocal autoindent
setlocal backupcopy=
setlocal balloonexpr=
setlocal nobinary
setlocal nobreakindent
setlocal breakindentopt=
setlocal bufhidden=
setlocal buflisted
setlocal buftype=
setlocal nocindent
setlocal cinkeys=0{,0},0),:,0#,!^F,o,O,e
setlocal cinoptions=
setlocal cinwords=if,else,while,do,for,switch
setlocal colorcolumn=
setlocal comments=:#
setlocal commentstring=#\ %s
setlocal complete=.,w,b,u,t,i
setlocal concealcursor=
setlocal conceallevel=0
setlocal completefunc=youcompleteme#Complete
setlocal nocopyindent
setlocal cryptmethod=
setlocal nocursorbind
setlocal nocursorcolumn
setlocal nocursorline
setlocal define=
setlocal dictionary=
setlocal nodiff
setlocal equalprg=
setlocal errorformat=
setlocal expandtab
if &filetype != 'yaml'
setlocal filetype=yaml
endif
setlocal fixendofline
setlocal foldcolumn=0
setlocal foldenable
setlocal foldexpr=0
setlocal foldignore=#
setlocal foldlevel=0
set foldmarker=#{,#}
setlocal foldmarker=#{,#}
set foldmethod=marker
setlocal foldmethod=marker
setlocal foldminlines=1
setlocal foldnestmax=20
setlocal foldtext=foldtext()
setlocal formatexpr=
setlocal formatoptions=croql
setlocal formatlistpat=^\\s*\\d\\+[\\]:.)}\\t\ ]\\s*
setlocal formatprg=
setlocal grepprg=
setlocal iminsert=2
setlocal imsearch=2
setlocal include=
setlocal includeexpr=
setlocal indentexpr=GetYAMLIndent(v:lnum)
setlocal indentkeys=!^F,o,O,0#,0},0],<:>,0-
setlocal noinfercase
setlocal iskeyword=@,48-57,_,192-255
setlocal keywordprg=
set linebreak
setlocal linebreak
setlocal nolisp
setlocal lispwords=
setlocal nolist
setlocal makeencoding=
setlocal makeprg=
setlocal matchpairs=(:),{:},[:]
setlocal modeline
setlocal modifiable
setlocal nrformats=bin,octal,hex
set number
setlocal number
setlocal numberwidth=4
setlocal omnifunc=
setlocal path=
setlocal nopreserveindent
setlocal nopreviewwindow
setlocal quoteescape=\\
setlocal noreadonly
set relativenumber
setlocal relativenumber
setlocal norightleft
setlocal rightleftcmd=search
setlocal noscrollbind
setlocal shiftwidth=2
setlocal noshortname
setlocal signcolumn=auto
setlocal nosmartindent
setlocal softtabstop=2
setlocal nospell
setlocal spellcapcheck=[.?!]\\_[\\])'\"\	\ ]\\+
setlocal spellfile=
setlocal spelllang=en
setlocal statusline=%!airline#statusline(2)
setlocal suffixesadd=
setlocal swapfile
setlocal synmaxcol=200
if &syntax != 'yaml'
setlocal syntax=yaml
endif
setlocal tabstop=2
setlocal tagcase=
setlocal tags=
setlocal textwidth=0
setlocal thesaurus=
setlocal noundofile
setlocal undolevels=-123456
setlocal nowinfixheight
setlocal nowinfixwidth
setlocal wrap
setlocal wrapmargin=0
let s:l = 1 - ((0 * winheight(0) + 23) / 46)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
1
normal! 0
wincmd w
exe 'vert 1resize ' . ((&columns * 106 + 87) / 174)
exe 'vert 2resize ' . ((&columns * 67 + 87) / 174)
tabnext 1
if exists('s:wipebuf')
  silent exe 'bwipe ' . s:wipebuf
endif
unlet! s:wipebuf
set winheight=4 winwidth=26 shortmess=filnxtToOIc
set winminheight=4 winminwidth=26
let s:sx = expand("<sfile>:p:r")."x.vim"
if file_readable(s:sx)
  exe "source " . fnameescape(s:sx)
endif
let &so = s:so_save | let &siso = s:siso_save
doautoall SessionLoadPost
unlet SessionLoad
" vim: set ft=vim :
