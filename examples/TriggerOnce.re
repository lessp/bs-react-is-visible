module Style = {
  let fixed = ReactDOMRe.Style.make(~position="fixed", ~right="2rem", ());
};

let options: ReactIsVisible.options = {triggerOnce: true};

[@react.component]
let make = () => {
  let (isVisible, ref) = ReactIsVisible.useIsVisible(~options, ());

  <div style=Basic.Style.wrapper>
    <h1> {"Scroll down" |> React.string} </h1>
    <h2 style=Style.fixed>
      {"Was triggered: " ++ string_of_bool(isVisible) ++ "" |> React.string}
    </h2>
    <div ref style={Basic.Style.box(isVisible)}>
      {(isVisible ? "I'm visible!" : "I'm not visible!") |> React.string}
    </div>
  </div>;
};