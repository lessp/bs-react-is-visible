module VO = {
  [@bs.val] [@bs.scope "VisibilityObserver"] [@bs.module "react-is-visible"]
  external unwatch: Dom.element => unit = "unwatch";

  [@bs.val] [@bs.scope "VisibilityObserver"] [@bs.module "react-is-visible"]
  external watch: (Dom.element, Js.Json.t => unit) => unit = "watch";

  [@bs.val] [@bs.scope "VisibilityObserver"] [@bs.module "react-is-visible"]
  external getSubscribers: unit => 't = "getSubscribers";

  module Decode = {
    let entry = entry => Json.Decode.(entry |> field("isIntersecting", bool));
  };
};

let useIsVisible = () => {
  let (isVisible, setIsVisible) = React.useState(() => false);
  let nodeRef = React.useRef(Js.Nullable.null);

  React.useEffect1(
    () => {
      let domElement =
        switch (nodeRef |> React.Ref.current |> Js.Nullable.toOption) {
        | Some(el) =>
          VO.watch(el, entry => setIsVisible(_ => entry |> VO.Decode.entry));
          Some(el);
        | None => None
        };

      switch (domElement) {
      | Some(e) => Some(() => VO.unwatch(e))
      | None => None
      };
    },
    [|nodeRef|],
  );

  (isVisible, ReactDOMRe.Ref.domRef(nodeRef));
};
