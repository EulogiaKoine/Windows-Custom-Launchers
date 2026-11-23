# Windows Custom Launchers

설치 필요 목록
1. 크롬
2. 카카오
3. VSCode
4. 옵시디언
5. Brave Browser

```cmd
wgemini
google (검색어)
kakao
obsidian
vscode
ymusic
capture

--- 2026.11.24 추가: svelte/react 간이 컴파일러 --
compile-page <target file> <outDir=.>
  : 대상 svelte/react 파일을 단일 html로 컴파일 및 번들링. 간접적으로 의존하는 파일들 포함.
  [--preflight] : tcss preflight 적용

run-page <target file>
  : 대상 svelte/react 파일을 live 모드로 호스팅 및 브라우저에서 즉시 실행. 파일 생성 없음.
  [--preflight] : tcss preflight 적용
  [--port=3000 / -p] : 호스팅 포트 지정
  [--no-open] : 브라우저 실행 없음

install-page-compile-config
  : IDE 자동완성용 tsconfig.json와 node_modules 심링크(junction) 추가. tsconfig는 복사가 아닌 extends 옵션이며 node_modules도 심링크라 용량은 매우 적음.
  [--force] : 기존 tsconfig.json가 존재하면 덮어씌움. 기본값 false.
  [--clean] : tsconfig.json와 node_modules 심링크 제거.
```
