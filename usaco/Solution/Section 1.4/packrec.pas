{
ID: a_zaky01
PROG: packrec
LANG: PASCAL
}

var
  i,int,int1,int2,int3,int4,count:integer;
  area:longint;
  linput,winput:array[1..4] of integer;
  used:array[1..100] of boolean;
  fin,fout:text;

procedure clean;
  var
    i:integer;

  begin
    for i:=1 to 100 do used[i]:=false;
  end;

procedure check(w,l:integer);
  begin
    inc(count);
    if (area=0) or (area>w*l) then
        begin
          area:=w*l;
          fillchar(used,sizeof(used),false);
          if w>l then used[l]:=true
            else used[w]:=true;
        end
      else if area=w*l then
        if w>l then used[l]:=true
          else used[w]:=true;
  end;

procedure pack1(w,l,k:integer);
  begin
    if k>4 then check(w,l)
      else if k=1 then
        begin
          pack1(winput[1],linput[1],2);
          pack1(linput[1],winput[1],2);
        end
      else
        begin
          if l>linput[k] then pack1((w+winput[k]),l,(k+1))
            else pack1((w+winput[k]),linput[k],(k+1));
          if l>winput[k] then pack1((w+linput[k]),l,(k+1))
            else pack1((w+linput[k]),winput[k],(k+1));
        end;
  end;

procedure pack2(w,l,k:integer);
  var
    templ,tempw:integer;

  begin
    if k>4 then
      begin
        templ:=l+linput[int];
        if winput[int]>w then tempw:=winput[int]
          else tempw:=w;
        check(tempw,templ);
        templ:=l+winput[int];
        if linput[int]>w then tempw:=linput[int]
          else tempw:=w;
        check(tempw,templ);
      end
    else if ((int=1) and (k=2)) or ((k=1) and (int<>1)) then
      begin
        pack2(winput[k],linput[k],k+1);
        pack2(linput[k],winput[k],k+1);
      end
    else if k<>int then
      begin
        if l>linput[k] then pack2((w+winput[k]),l,(k+1))
          else pack2((w+winput[k]),linput[k],(k+1));
        if l>winput[k] then pack2((w+linput[k]),l,(k+1))
          else pack2((w+linput[k]),winput[k],(k+1));
      end
    else pack2(w,l,k+1);
  end;

procedure pack3(w,l,k:integer);
  var
    templ,tempw:integer;

  begin
    if k>4 then
      begin
        templ:=l+linput[int1];
        if winput[int1]>=w then tempw:=winput[int1]+winput[int2]
          else tempw:=w+winput[int2];
        if templ<=linput[int2] then templ:=linput[int2];
        check(tempw,templ);
        templ:=l+linput[int1];
        if winput[int1]>=w then tempw:=winput[int1]+linput[int2]
          else tempw:=w+linput[int2];
        if templ<=winput[int2] then templ:=winput[int2];
        check(tempw,templ);
        templ:=l+winput[int1];
        if linput[int1]>=w then tempw:=linput[int1]+winput[int2]
          else tempw:=w+winput[int2];
        if templ<=linput[int2] then templ:=linput[int2];
        check(tempw,templ);
        templ:=l+winput[int1];
        if linput[int1]>=w then tempw:=linput[int1]+linput[int2]
          else tempw:=w+linput[int2];
        if templ<=winput[int2] then templ:=winput[int2];
        check(tempw,templ);
      end
    else if (k<>int1) and (k<>int2) then
      if w=0 then
        begin
          pack3(winput[k],linput[k],k+1);
          pack3(linput[k],winput[k],k+1);
        end
      else
        begin
          if l>linput[k] then pack3((w+winput[k]),l,(k+1))
            else pack3((w+winput[k]),linput[k],(k+1));
          if l>winput[k] then pack3((w+linput[k]),l,(k+1))
            else pack3((w+linput[k]),winput[k],(k+1));
        end
    else pack3(w,l,k+1);
  end;

procedure pack4(w,l,k:integer);
  var
    templ,tempw:integer;

  procedure pack(w2,l2,k2:integer);
    begin
      if k2>2 then
        begin
          tempw:=w2+w;
          if l>l2 then templ:=l
            else templ:=l2;
          check(tempw,templ);
        end
      else if k2=1 then
        begin
          pack(winput[int1],linput[int1],(k2+1));
          pack(linput[int1],winput[int1],(k2+1));
        end
      else
        begin
          if w2>winput[int2] then pack(w2,(l2+linput[int2]),(k2+1))
            else pack(winput[int2],(l2+linput[int2]),(k2+1));
          if w2>linput[int2] then pack(w2,(l2+winput[int2]),(k2+1))
            else pack(linput[int2],(l2+winput[int2]),(k2+1));
        end;
    end;

  begin
    if k>4 then pack(0,0,1)
    else if (k<>int1) and (k<>int2) then
      if w=0 then
        begin
          pack4(winput[k],linput[k],k+1);
          pack4(linput[k],winput[k],k+1);
        end
      else
        begin
          if l>linput[k] then pack4((w+winput[k]),l,(k+1))
            else pack4((w+winput[k]),linput[k],(k+1));
          if l>winput[k] then pack4((w+linput[k]),l,(k+1))
            else pack4((w+linput[k]),winput[k],(k+1));
        end
    else pack4(w,l,k+1);
  end;

procedure pack6;
  var
    templ,tempw,wlu,wld,wru,wrd,llu,lld,lru,lrd:integer;

  procedure finalize;
    begin
      if wlu<wld then
        if wlu+wru<wld+wrd then tempw:=wld+wrd
          else tempw:=wlu+wru
      else if wrd<wru then tempw:=wlu+wru
        else tempw:=wlu+wrd;
      if lld+llu>lrd+lru then templ:=lld+llu
        else templ:=lrd+lru;
      check(tempw,templ);
    end;

  procedure pack;
    begin
      wlu:=winput[int3];
      llu:=linput[int3];
      wru:=winput[int4];
      lru:=linput[int4];
      if llu+lld>lrd then finalize;
      wru:=linput[int4];
      lru:=winput[int4];
      if llu+lld>lrd then finalize;
      wlu:=linput[int3];
      llu:=winput[int3];
      if llu+lld>lrd then finalize;
      wru:=winput[int4];
      lru:=linput[int4];
      if llu+lld>lrd then finalize;
    end;

  begin
    wld:=winput[int1];
    lld:=linput[int1];
    wrd:=winput[int2];
    lrd:=linput[int2];
    if lrd>=lld then pack;
    wrd:=linput[int2];
    lrd:=winput[int2];
    if lrd>=lld then pack;
    wld:=linput[int1];
    lld:=winput[int1];
    if lrd>=lld then pack;
    wrd:=winput[int2];
    lrd:=linput[int2];
    if lrd>=lld then pack;
  end;

begin
  assign(fin,'packrec.in');
  assign(fout,'packrec.out');
  reset(fin);
  rewrite(fout);
  for i:=1 to 4 do readln(fin,winput[i],linput[i]);
  area:=0;
  count:=0;
  pack1(0,0,1);
  for int:=1 to 4 do pack2(0,0,1);
  for int1:=1 to 4 do
    for int2:=1 to 4 do
      if int1<>int2 then pack3(0,0,1);
  for int1:=1 to 3 do
    for int2:=(int1+1) to 4 do pack4(0,0,1);
  for int1:=1 to 4 do
    for int2:=1 to 4 do
      for int3:=1 to 4 do
        for int4:=1 to 4 do
          if (int1<>int2) and (int1<>int3) and (int1<>int4) and (int2<>int3) and (int2<>int4) and (int3<>int4) then pack6;
  writeln(fout,area);
  for i:=1 to 100 do
    if used[i] then writeln(fout,i,' ',(area div i));
  close(fin);
  close(fout);
end.
