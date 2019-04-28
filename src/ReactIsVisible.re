module VO = {
  [@bs.val] [@bs.scope "VisibilityObserver"] [@bs.module "react-is-visible"]
  external unwatch: Dom.element => unit = "unwatch";

  [@bs.val] [@bs.scope "VisibilityObserver"] [@bs.module "react-is-visible"]
  external watch: (Dom.element, Js.Json.t => unit) => unit = "watch";

  module Decode = {
    let entry = entry => Json.Decode.(entry |> field("isIntersecting", bool));
  };
};

let useIsVisible = () => {
  let (isVisible, setIsVisible) = React.useState(() => false);

  let handleRef =
    React.useCallback0(domRef =>
      switch (domRef |> Js.Nullable.toOption) {
      | Some(domElement) =>
        VO.watch(domElement, entry =>
          setIsVisible(_ => entry |> VO.Decode.entry)
        )
      | None => ()
      }
    );

  (isVisible, ReactDOMRe.Ref.callbackDomRef(handleRef));
};
